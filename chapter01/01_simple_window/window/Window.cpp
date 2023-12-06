#include "Window.h"
#include "Logger.h"

bool Window::init(unsigned int width, unsigned int height, std::string title)
{
  if (!glfwInit())
  {
    Logger::log(1, "%s: glfwInit() error\n", __FUNCTION__);
    return false;
  }

  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

  if (!mWindow)
  {
    Logger::log(1, "%s: Cluld not create window.\n", __FUNCTION__);
    glfwTerminate();
    return false;
  }

  Logger::log(1, "%s: Window successfully initialized", __FUNCTION__);
  return true;
}

void Window::mainLoop()
{
  while (!glfwWindowShouldClose(mWindow))
  {
    /* poll events in a loop */
    glfwPollEvents();
  }
  
}

void Window::cleanup()
{
  Logger::log(1, "%s: Terminating Window.\n");
  glfwDestroyWindow(mWindow);
  glfwTerminate();
}