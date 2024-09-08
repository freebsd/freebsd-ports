# Copyright (c) 2020 Ultimaker B.V.
# pynest2d is released under the terms of the LGPLv3 or higher.

project(pynest2d)
cmake_minimum_required(VERSION 3.6)  # Lowest version it's been tested with.

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Requirements.
# FIXME: Remove the code for CMake <3.12 once we have switched over completely.
# FindPython3 is a new module since CMake 3.12. It deprecates FindPythonInterp and FindPythonLibs.
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    # FIXME: Use FindPython3 to find Python, new in CMake 3.12.
    # However currently on our CI server it finds the wrong Python version and then doesn't find the headers.
    find_package(PythonInterp 3.5 REQUIRED)
    find_package(PythonLibs 3.5 REQUIRED)

else()
    # Use FindPython3 for CMake >=3.12
    find_package(Python3 3.5 REQUIRED COMPONENTS Interpreter Development)
endif()
execute_process(COMMAND ${Python_EXECUTABLE} -c "import sysconfig; print(sysconfig.get_path('platlib'), end='')" OUTPUT_VARIABLE Python_SITEARCH)

find_package(SIP REQUIRED)  # To create Python bindings.
include(SIPMacros)
find_package(libnest2d REQUIRED)  # The library we're creating bindings for.
find_package(Clipper REQUIRED)  # Dependency of libnest2d.
find_package(NLopt REQUIRED)  # Dependency of libnest2d.
find_package(Boost REQUIRED)  # Dependency of libnest2d.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLIBNEST2D_GEOMETRIES_clipper -DLIBNEST2D_OPTIMIZERS_nlopt -DLIBNEST2D_THREADING_std")  # Tell libnest2d to use Clipper and NLopt, and standard threads.

# Some build options.
set(CMAKE_CXX_STANDARD 17)
if(APPLE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()
if(UNIX)
    # Want to be able to move symbols from the Clipper library.
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
endif()
if(NOT DEFINED LIB_SUFFIX)
    set(LIB_SUFFIX "")
endif()

# Building and linking.
set(SIP_EXTRA_FILES_DEPEND
    python/BottomLeftConfig.sip
    python/Box.sip
    python/Circle.sip
    python/DJDHeuristicConfig.sip
    python/Item.sip
    python/ItemGroup.sip
    python/NfpConfig.sip
    python/Point.sip
    python/Rectangle.sip
    python/String.sip
)

set(SIP_EXTRA_OPTIONS -g -n PyQt6.sip)  # Always release the GIL before calling C++ methods. -n PyQt6.sip is required to not get the PyCapsule error
set(SIP_EXTRA_INCLUDE_DIRS ${SIP_INCLUDE_DIRS} ${Python3_INCLUDE_DIRS} ${CLIPPER_INCLUDE_DIRS} ${NLopt_INCLUDE_DIRS} ${LIBNEST2D_INCLUDE_DIRS})
generate_sip_python_module_code(pynest2d python/pynest2d.sip python/pynest2d.sip "" pynest2d_cpp_files)
build_sip_python_module(pynest2d python/pynest2d.sip "${pynest2d_cpp_files}" "${CLIPPER_LIBRARIES};${NLopt_LIBRARIES}")
