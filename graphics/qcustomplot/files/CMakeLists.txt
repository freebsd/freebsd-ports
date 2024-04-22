cmake_minimum_required(VERSION 3.18.4)

SET(QCustomPlot_MAJOR_VERSION "2")
SET(QCustomPlot_MINOR_VERSION "1")
SET(QCustomPlot_PATCH_VERSION "1")

set(QCustomPlot_VERSION "${QCustomPlot_MAJOR_VERSION}.${QCustomPlot_MINOR_VERSION}.${QCustomPlot_PATCH_VERSION}")
set(QCustomPlot_SOVERSION "${QCustomPlot_MAJOR_VERSION}")

PROJECT(QCustomPlot LANGUAGES CXX VERSION ${QCustomPlot_VERSION})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(GNUInstallDirs)
include(FeatureSummary)

#-----------------------------------------------------------#
# Dependencies
#-----------------------------------------------------------#

set(REQUIRED_QT_COMPONENTS Core Widgets PrintSupport)

set(MIN_REQUIRED_QT5_VERSION "5.12")
set(MIN_REQUIRED_QT6_VERSION "6.2.0")


find_package(Qt${USE_QT_VERSION} ${MIN_REQUIRED_QT${USE_QT_VERSION}_VERSION}
  COMPONENTS ${REQUIRED_QT_COMPONENTS} REQUIRED)
set(QT_VERSION_MAJOR ${USE_QT_VERSION})


#-----------------------------------------------------------#
# Definitions
#-----------------------------------------------------------#

set(LIB5_SUFFIX "-qt5")
set(LIB6_SUFFIX "Qt6")
set(LIB_SUFFIX "${LIB${QT_VERSION_MAJOR}_SUFFIX}")

set(LIB_NAME QCustomPlot${LIB_SUFFIX})
set(CMAKE_CONFIG_FILE_NAME ${LIB_NAME}Config.cmake)
set(CMAKE_CONFIG_LIB_NAMES ${LIB_NAME} lib${LIB_NAME})

set(INC5_SUBDIR "")
set(INC6_SUBDIR "${LIB_NAME}")
set(QCUSTOMPLOT_INSTALL_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}/${INC${QT_VERSION_MAJOR}_SUBDIR}")


#-----------------------------------------------------------#
# Compiler Settings
#-----------------------------------------------------------#

#set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Only enable strict warnings in debug mode
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror -pedantic")

# As per the author of the library, we should export the symbols under
# MS-Windows.
add_definitions(-DQCUSTOMPLOT_COMPILE_LIBRARY)

#-----------------------------------------------------------#
# Sources
#-----------------------------------------------------------#

add_library(${LIB_NAME} SHARED qcustomplot.cpp)

set_target_properties(${LIB_NAME} PROPERTIES
  VERSION ${QCustomPlot_VERSION}
  SOVERSION ${QCustomPlot_SOVERSION})

target_link_libraries(${LIB_NAME}
  Qt${QT_VERSION_MAJOR}::Widgets
  Qt${QT_VERSION_MAJOR}::PrintSupport)

#-----------------------------------------------------------#
# Installation
#-----------------------------------------------------------#

install(TARGETS ${LIB_NAME}
  EXPORT ${LIB_NAME}Targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${QCUSTOMPLOT_INSTALL_INCLUDEDIR})

install(FILES qcustomplot.h DESTINATION "${QCUSTOMPLOT_INSTALL_INCLUDEDIR}")

install(EXPORT ${LIB_NAME}Targets
  FILE ${LIB_NAME}Targets.cmake
  NAMESPACE ${LIB_NAME}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIB_NAME})

include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIB_NAME})

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/${LIB_NAME}Config.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIB_NAME})

#-----------------------------------------------------------#
# Summary
#-----------------------------------------------------------#

feature_summary(FATAL_ON_MISSING_REQUIRED_PACKAGES WHAT ALL)

