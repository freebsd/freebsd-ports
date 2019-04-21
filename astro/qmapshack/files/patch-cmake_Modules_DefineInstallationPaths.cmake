--- cmake/Modules/DefineInstallationPaths.cmake.orig	2018-09-08 09:17:56 UTC
+++ cmake/Modules/DefineInstallationPaths.cmake
@@ -97,7 +97,7 @@ if (UNIX)
     FORCE
   )
   SET(MAN_INSTALL_DIR
-    "${SHARE_INSTALL_PREFIX}/man"
+    "${CMAKE_INSTALL_PREFIX}/man"
     CACHE PATH "The ${_PROJECT_NAME} man install dir (default prefix/man)"
     FORCE
   )
