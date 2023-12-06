--- cmake/Macros/PySideModules.cmake.orig	2023-11-27 12:04:49 UTC
+++ cmake/Macros/PySideModules.cmake
@@ -107,7 +107,7 @@ macro(create_pyside_module)
     get_target_property(qt_core_includes Qt${QT_MAJOR_VERSION}::Core
                         INTERFACE_INCLUDE_DIRECTORIES)
     set(shiboken_include_dir_list ${pyside6_SOURCE_DIR} ${qt_platform_includes}
-        ${qt_core_includes})
+        ${qt_core_includes} ${CMAKE_INSTALL_PREFIX}/include)
     if(module_ADDITIONAL_INCLUDE_DIRS)
         list(APPEND shiboken_include_dir_list ${${module_ADDITIONAL_INCLUDE_DIRS}})
     endif()
