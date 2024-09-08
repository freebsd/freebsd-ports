# Copyright (c) 2018 Ultimaker B.V.
# Cura is released under the terms of the LGPLv3 or higher.

include(CTest)
include(CMakeParseArguments)

# FIXME: The new FindPython3 finds the system's Python3.6 rather than the Python3.5 that we built for Cura's environment.
# So we're using the old method here, with FindPythonInterp for now.
#find_package(PythonInterp 3 REQUIRED)
#
#set(Python3_EXECUTABLE ${PYTHON_EXECUTABLE})
find_package(Python3 REQUIRED)

add_custom_target(test-verbose COMMAND ${CMAKE_CTEST_COMMAND} --verbose)

function(cura_add_test)
    set(_single_args NAME DIRECTORY PYTHONPATH)
    cmake_parse_arguments("" "" "${_single_args}" "" ${ARGN})

    if(NOT _NAME)
        message(FATAL_ERROR "cura_add_test requires a test name argument")
    endif()

    if(NOT _DIRECTORY)
        message(FATAL_ERROR "cura_add_test requires a directory to test")
    endif()

    if(NOT _PYTHONPATH)
        set(_PYTHONPATH ${_DIRECTORY})
    endif()
    
    if(WIN32)
        string(REPLACE "|" "\\;" _PYTHONPATH ${_PYTHONPATH})
        set(_PYTHONPATH "${_PYTHONPATH}\\;$ENV{PYTHONPATH}")
    else()
        string(REPLACE "|" ":" _PYTHONPATH ${_PYTHONPATH})
        set(_PYTHONPATH "${_PYTHONPATH}:$ENV{PYTHONPATH}")
    endif()

    get_test_property(${_NAME} ENVIRONMENT test_exists) #Find out if the test exists by getting a property from it that always exists (such as ENVIRONMENT because we set that ourselves).
    if (NOT ${test_exists})
        add_test(
            NAME ${_NAME}
            COMMAND ${Python3_EXECUTABLE} -m pytest --junitxml=${CMAKE_BINARY_DIR}/junit-${_NAME}.xml ${_DIRECTORY}
        )
        set_tests_properties(${_NAME} PROPERTIES ENVIRONMENT LANG=C)
        set_tests_properties(${_NAME} PROPERTIES ENVIRONMENT "PYTHONPATH=${_PYTHONPATH}")
    else()
        message(WARNING "Duplicate test ${_NAME}!")
    endif()
endfunction()


#Add code style test.
add_test(
    NAME "code-style"
    COMMAND ${Python3_EXECUTABLE} run_mypy.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

#Add test for import statements which are not compatible with all builds
add_test(
    NAME "invalid-imports"
    COMMAND ${Python3_EXECUTABLE} scripts/check_invalid_imports.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

cura_add_test(NAME pytest-main DIRECTORY ${CMAKE_SOURCE_DIR}/tests PYTHONPATH "${CMAKE_SOURCE_DIR}|${URANIUM_DIR}")

file(GLOB_RECURSE _plugins plugins/*/__init__.py)
foreach(_plugin ${_plugins})
    get_filename_component(_plugin_directory ${_plugin} DIRECTORY)
    if(EXISTS ${_plugin_directory}/tests)
        get_filename_component(_plugin_name ${_plugin_directory} NAME)
        cura_add_test(NAME pytest-${_plugin_name} DIRECTORY ${_plugin_directory} PYTHONPATH "${_plugin_directory}|${CMAKE_SOURCE_DIR}|${URANIUM_DIR}")
    endif()
endforeach()

#Add test for whether the shortcut alt-keys are unique in every translation.
add_test(
    NAME "shortcut-keys"
    COMMAND ${Python3_EXECUTABLE} scripts/check_shortcut_keys.py
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
