--- cmake/install-package-config-files.cmake.orig	2024-08-30 10:43:51 UTC
+++ cmake/install-package-config-files.cmake
@@ -2,7 +2,7 @@ function(osgearth_install_package_config_files TARGET 
 
     include(CMakePackageConfigHelpers)
 
-    set(PACKAGE_INSTALL_DIR share/osgearth)
+    set(PACKAGE_INSTALL_DIR share/cmake/Modules/osgEarth)
     #set(INCLUDE_INSTALL_DIR ${CMAKE_INSTALL_INCLUDEDIR})
     #set(LIBRARY_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR})
 
