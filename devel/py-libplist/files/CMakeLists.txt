set(CMAKE_MODULE_PATH
    ${CMAKE_SOURCE_DIR}/cmake
    ${CMAKE_SOURCE_DIR}/cmake/modules)

# Required by SWIG.
include_directories(/usr/local/include)

find_package(Cython REQUIRED)
find_package(SWIG REQUIRED)
find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)

add_subdirectory(cython)
add_subdirectory(swig)
