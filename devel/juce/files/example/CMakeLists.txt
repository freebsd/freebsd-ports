cmake_minimum_required(VERSION 3.22)
project(JuceSimpleGui VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Point to your local JUCE 9 installation
list(APPEND CMAKE_PREFIX_PATH "/usr/local/include/JUCE-9.0.0")
find_package(JUCE CONFIG REQUIRED)

# 2. Add the UI App executable target
juce_add_gui_app(SimpleGuiApp PRODUCT_NAME "SimpleGuiApp")
target_sources(SimpleGuiApp PRIVATE example.cpp)

# 3. Explicitly link core framework libraries
target_link_libraries(SimpleGuiApp PRIVATE
    juce::juce_core
    juce::juce_graphics
    juce::juce_gui_basics
    juce::juce_gui_extra
    juce::juce_recommended_config_flags
)

# 4. Explicitly bind fallback OS libraries required on BSD/Linux systems
find_package(ZLIB REQUIRED)
target_link_libraries(SimpleGuiApp PRIVATE ZLIB::ZLIB m pthread)

