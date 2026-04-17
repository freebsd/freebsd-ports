cmake_minimum_required(VERSION 3.23)

project(jkqtplotter_examples_all LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.0 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

find_package(JKQTPlotter6 REQUIRED)

qt_add_executable(jkqtplotter_examples_all main.cpp)

target_link_libraries(jkqtplotter_examples_all PRIVATE
    Qt6::Core
    Qt6::Widgets
    JKQTPlotter6::JKQTPlotter6
)
