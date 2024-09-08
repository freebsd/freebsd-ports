project(uranium NONE)

cmake_minimum_required(VERSION 3.6)

message(STATUS ${CMAKE_MODULE_PATH})

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/
                      ${CMAKE_MODULE_PATH})
include(UraniumTranslationTools)

include(GNUInstallDirs)

find_package(PythonInterp 3 REQUIRED)

message("Using python version ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}")

# # Checks using pylint
# Note that we use exit 0 here to not mark the build as a failure on check failure
# In addition, the specified pylint configuration uses the spellchecker plugin. This required python-enchant to be installed.
add_custom_target(check)
add_custom_command(TARGET check POST_BUILD COMMAND "PYTHONPATH=${CMAKE_SOURCE_DIR}" ${PYTHON_EXECUTABLE} -m pylint --rcfile=${CMAKE_SOURCE_DIR}/pylint.cfg UM --msg-template=\"{path}:{line}: [{msg_id}({symbol}) , {obj}] {msg}\" > ${CMAKE_BINARY_DIR}/pylint.log || exit 0 WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

# # Check using Mypy
add_custom_target(typecheck)
add_custom_command(TARGET typecheck POST_BUILD COMMAND ${PYTHON_EXECUTABLE} run_mypy.py WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

# # Tests
include(UraniumTests)

# # Benchmarks
# add_custom_target(benchmark)
# file(GLOB bench_files tests/benchmarks/*/profile*.py)
# foreach(file ${bench_files})
#     add_custom_command(TARGET benchmark POST_BUILD COMMAND "PYTHONPATH=${CMAKE_SOURCE_DIR}" kernprof ARGS -l -v ${file})
# endforeach()


# Documentation
find_package(Doxygen)
if(${DOXYGEN_FOUND})
    add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif()

# Extract Strings
add_custom_target(extract-messages ${CMAKE_SOURCE_DIR}/scripts/extract-messages ${CMAKE_SOURCE_DIR} uranium)

# Build Translations
CREATE_TRANSLATION_TARGETS()


if(EXISTS /etc/debian_version)
    install(DIRECTORY UM DESTINATION lib${LIB_SUFFIX}/python${PYTHON_VERSION_MAJOR}/dist-packages)
else()
    install(DIRECTORY UM DESTINATION lib${LIB_SUFFIX}/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/site-packages)
endif()
install(FILES ${CMAKE_SOURCE_DIR}/cmake/UraniumTranslationTools.cmake
        DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/Modules/ )
install(DIRECTORY resources DESTINATION ${CMAKE_INSTALL_DATADIR}/uranium)

# Detect plugins to install
include(UraniumPluginInstall)

include(CPackConfig.cmake)
