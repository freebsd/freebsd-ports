--- sources/pyside6/cmake/Macros/PySideModules.cmake.orig	2024-10-09 13:33:59 UTC
+++ sources/pyside6/cmake/Macros/PySideModules.cmake
@@ -122,7 +122,7 @@ macro(create_pyside_module)
     get_target_property(qt_core_includes Qt${QT_MAJOR_VERSION}::Core
                         INTERFACE_INCLUDE_DIRECTORIES)
     set(shiboken_include_dir_list ${pyside6_SOURCE_DIR} ${qt_platform_includes}
-        ${qt_core_includes})
+        ${qt_core_includes} ${CMAKE_INSTALL_PREFIX}/include)
     if(module_ADDITIONAL_INCLUDE_DIRS)
         list(APPEND shiboken_include_dir_list ${${module_ADDITIONAL_INCLUDE_DIRS}})
     endif()
