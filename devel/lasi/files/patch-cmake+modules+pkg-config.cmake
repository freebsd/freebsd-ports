--- cmake/modules/pkg-config.cmake.orig	2008-12-31 14:38:25.000000000 -0500
+++ cmake/modules/pkg-config.cmake	2008-12-31 14:42:58.000000000 -0500
@@ -6,7 +6,7 @@
 if(PKG_CONFIG_EXECUTABLE)
   message(STATUS "Looking for pkg-config - found")
   set(pkg_config_true "")
-  set(PKG_CONFIG_DIR ${libdir}/pkgconfig)
+  set(PKG_CONFIG_DIR ${exec_prefix}/libdata/pkgconfig)
 else(PKG_CONFIG_EXECUTABLE)
   message(STATUS "Looking for pkg-config - not found")
   set(pkg_config_true "#")
