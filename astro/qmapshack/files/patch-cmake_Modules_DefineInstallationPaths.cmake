--- cmake/Modules/DefineInstallationPaths.cmake.orig	2014-08-18 10:08:14 UTC
+++ cmake/Modules/DefineInstallationPaths.cmake
@@ -101,7 +101,7 @@ if (UNIX)
     FORCE
   )
   SET(MAN_INSTALL_DIR
-    "${SHARE_INSTALL_PREFIX}/man"
+    "${CMAKE_INSTALL_PREFIX}/man"
     CACHE PATH "The ${_PROJECT_NAME} man install dir (default prefix/man)"
     FORCE
   )
