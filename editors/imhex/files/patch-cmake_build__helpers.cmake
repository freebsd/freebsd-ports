--- cmake/build_helpers.cmake.orig	2021-05-18 19:25:59 UTC
+++ cmake/build_helpers.cmake
@@ -49,6 +49,8 @@ macro(findLibraries)
         message(FATAL_ERROR "No valid version of Python 3 was found.")
     endif()
 
+    find_package(CURL REQUIRED)
+
     string(REPLACE "." ";" PYTHON_VERSION_MAJOR_MINOR ${Python_VERSION})
 
     list(LENGTH PYTHON_VERSION_MAJOR_MINOR PYTHON_VERSION_COMPONENT_COUNT)
@@ -162,7 +164,7 @@ macro(createPackage)
     foreach (plugin IN LISTS PLUGINS)
         add_subdirectory("plugins/${plugin}")
         set_target_properties(${plugin} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/plugins)
-        install(TARGETS ${plugin} RUNTIME DESTINATION ${PLUGINS_INSTALL_LOCATION})
+        install(TARGETS ${plugin} LIBRARY DESTINATION ${PLUGINS_INSTALL_LOCATION})
         add_dependencies(imhex ${plugin})
     endforeach()
 
