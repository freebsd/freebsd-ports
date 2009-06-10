--- cmake/Modules/DefineInstallationPaths.cmake.orig	2009-06-01 22:54:55.000000000 +0300
+++ cmake/Modules/DefineInstallationPaths.cmake	2009-06-01 22:59:02.000000000 +0300
@@ -101,7 +101,7 @@
     FORCE
   )
   SET(MAN_INSTALL_DIR
-    "${SHARE_INSTALL_PREFIX}/man"
+    "${CMAKE_INSTALL_PREFIX}/man"
     CACHE PATH "The ${_APPLICATION_NAME} man install dir (default prefix/man)"
     FORCE
   )
