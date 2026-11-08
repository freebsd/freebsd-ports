#include <iostream>
#include <glad/gl.h> // Glad goes first
#include <GLFW/glfw3.h>

int main() {
    // 1. Initialize your windowing library (e.g., GLFW)
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    glfwMakeContextCurrent(window);

    // 2. Initialize GLAD to load all OpenGL function pointers
    // gladLoadGL requires a function pointer loader from your window framework
    int version = gladLoadGL(glfwGetProcAddress);
    if (version == 0) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 3. Ready to use OpenGL functions!
    std::cout << "OpenGL Loaded! Version: "
              << GLAD_VERSION_MAJOR(version) << "."
              << GLAD_VERSION_MINOR(version) << std::endl;

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
