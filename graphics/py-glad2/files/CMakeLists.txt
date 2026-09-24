cmake_minimum_required(VERSION 3.10)
project(OpenGLProject)

# 1. Include Glad's header directory so your compiler can find <glad/gl.h>
include_directories(include)

# 2. Add both your source files AND Glad's generated C file
add_executable(MyGame
    src/main.cpp
    src/gl.c
)

# 3. Link your windowing libraries (like GLFW or SDL)
find_package(glfw3 REQUIRED)
target_link_libraries(MyGame glfw)
