cmake_minimum_required(VERSION 3.23)
project(jkqtplotter_simple_plot LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Prefer Qt6, fall back to Qt5
find_package(QT NAMES Qt6 COMPONENTS Core Gui Widgets PrintSupport Svg Xml REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets PrintSupport Svg Xml REQUIRED)

# Find JKQTPlotter for the detected Qt version
find_package(JKQTPlotter${QT_VERSION_MAJOR} REQUIRED)

add_executable(simple_plot main.cpp)

target_link_libraries(simple_plot PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    JKQTPlotter${QT_VERSION_MAJOR}::JKQTPlotter${QT_VERSION_MAJOR}
)
