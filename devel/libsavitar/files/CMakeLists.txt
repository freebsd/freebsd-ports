project(savitar)
cmake_minimum_required(VERSION 3.8)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(GenerateExportHeader)

option(BUILD_PYTHON "Build " ON)
option(BUILD_STATIC "Build as a static library" OFF)
option(BUILD_TESTS "Building the test-suite" OFF)

if(BUILD_TESTS)
    message(STATUS "Building with tests...")
    find_package(GTest REQUIRED)
    find_package(Threads QUIET)
endif()

#add_subdirectory(pugixml)

if(BUILD_PYTHON)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

    # FIXME: Remove the code for CMake <3.12 once we have switched over completely.
    # FindPython3 is a new module since CMake 3.12. It deprecates FindPythonInterp and FindPythonLibs.
    if(${CMAKE_VERSION} VERSION_LESS 3.12)
        # FIXME: Use FindPython3 to find Python, new in CMake 3.12.
        # However currently on our CI server it finds the wrong Python version and then doesn't find the headers.
        find_package(PythonInterp 3.4 REQUIRED)
        find_package(PythonLibs 3.4 REQUIRED)

    else()
        # Use FindPython3 for CMake >=3.12
        find_package(Python3 3.4 REQUIRED COMPONENTS Interpreter Development)
    endif()
    execute_process(COMMAND ${Python_EXECUTABLE} -c "import sysconfig; print(sysconfig.get_path('platlib'), end='')" OUTPUT_VARIABLE Python_SITEARCH)

    find_package(SIP REQUIRED)
    if(NOT DEFINED LIB_SUFFIX)
        set(LIB_SUFFIX "")
    endif()
    include(SIPMacros)

    include_directories(include/ python/ src/ ${SIP_INCLUDE_DIRS} ${Python3_INCLUDE_DIRS})
endif()

set(CMAKE_CXX_STANDARD 17)

if(APPLE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

set(savitar_SRCS
    src/Namespace.cpp
    src/ThreeMFParser.cpp
    src/SceneNode.cpp
    src/Scene.cpp
    src/MeshData.cpp
    src/Vertex.cpp
    src/Face.cpp
)

set(savitar_HDRS
    include/Savitar/Face.h
    include/Savitar/MeshData.h
    include/Savitar/MetadataEntry.h
    include/Savitar/Namespace.h
    include/Savitar/Scene.h
    include/Savitar/SceneNode.h
    include/Savitar/ThreeMFParser.h
    include/Savitar/Types.h
    include/Savitar/Vertex.h
    ${CMAKE_CURRENT_BINARY_DIR}/src/SavitarExport.h
)

set(SAVITAR_VERSION 0.1.2)
set(SAVITAR_SOVERSION 0)

set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_FULL_LIBDIR})

if(BUILD_STATIC)
    add_library(Savitar STATIC ${savitar_SRCS})
else()
    add_library(Savitar SHARED ${savitar_SRCS})
endif()

set(Savitar_LINK_LIBRARIES pugixml)
if(CMAKE_USE_PTHREADS_INIT)
    list(APPEND Savitar_LINK_LIBRARIES pthread)
endif()
target_link_libraries(Savitar PUBLIC ${Savitar_LINK_LIBRARIES})

if(NOT WIN32 OR CMAKE_COMPILER_IS_GNUCXX)
    set_target_properties(Savitar PROPERTIES COMPILE_FLAGS -fPIC)
endif()

if(BUILD_PYTHON)
    set(SIP_EXTRA_FILES_DEPEND python/Types.sip python/MeshData.sip python/SceneNode.sip python/Scene.sip)
    #set(SIP_EXTRA_SOURCE_FILES python/Types.cpp)
    set(SIP_EXTRA_OPTIONS -g -n PyQt6.sip) # -g means always release the GIL before calling C++ methods. -n PyQt6.sip is required to not get the PyCapsule error
    generate_sip_python_module_code(pySavitar python/pySavitar.sip python/pySavitar.sip "${SIP_EXTRA_FILES_DEPEND}" pySavitar_cpp_files)
    build_sip_python_module(pySavitar python/pySavitar.sip "${pySavitar_cpp_files};${SIP_EXTRA_SOURCE_FILES}" "" Savitar)
endif()

target_include_directories(Savitar PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

if(${CMAKE_BUILD_TYPE})
    if(${CMAKE_BUILD_TYPE} STREQUAL "Debug" OR ${CMAKE_BUILD_TYPE} STREQUAL "RelWithDebInfo")
        add_definitions(-DSAVITAR_DEBUG)
    endif()
endif()

set_target_properties(Savitar PROPERTIES
    FRAMEWORK FALSE
    VERSION ${SAVITAR_VERSION}
    SOVERSION ${SAVITAR_SOVERSION}
    PUBLIC_HEADER "${savitar_HDRS}"
    DEFINE_SYMBOL MAKE_SAVITAR_LIB
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN 1
)

generate_export_header(Savitar
    EXPORT_FILE_NAME src/SavitarExport.h
)
# This is required when building out-of-tree.
# The compiler won't find the generated header otherwise.
include_directories(${CMAKE_BINARY_DIR}/src)

install(TARGETS Savitar
    EXPORT Savitar-targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Savitar
)

install(EXPORT Savitar-targets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Savitar
)

configure_package_config_file(SavitarConfig.cmake.in ${CMAKE_BINARY_DIR}/SavitarConfig.cmake INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Savitar)
write_basic_package_version_file(${CMAKE_BINARY_DIR}/SavitarConfigVersion.cmake VERSION ${SAVITAR_VERSION} COMPATIBILITY SameMajorVersion)

# List of tests. For each test there must be a file tests/${NAME}.cpp.
set(savitar_TEST
    ThreeMFParserTest
    MeshDataTest
    NamespaceTest
)

# Compiling the test environment.
if (BUILD_TESTS)
    include_directories(${GTEST_INCLUDE_DIR})

    enable_testing()

    #To make sure that the tests are built before running them, add the building of these tests as an additional test.
    add_custom_target(build_all_tests)
    add_test(BuildTests "${CMAKE_COMMAND}" --build ${CMAKE_CURRENT_BINARY_DIR} --target build_all_tests)

    foreach (test ${savitar_TEST})
        add_executable(${test} tests/main.cpp tests/${test}.cpp)
        target_link_libraries(${test} Savitar ${GTEST_BOTH_LIBRARIES})
        add_test(${test} ${test})
        add_dependencies(build_all_tests ${test}) #Make sure that this gets built as part of the build_all_tests target.
    endforeach()
endif()

install(FILES
    ${CMAKE_BINARY_DIR}/SavitarConfig.cmake
    ${CMAKE_BINARY_DIR}/SavitarConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Savitar
)
