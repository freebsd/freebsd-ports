--- cmake/Modules/DefineInstallationPaths.cmake.orig	2020-03-27 08:07:31 UTC
+++ cmake/Modules/DefineInstallationPaths.cmake
@@ -59,7 +59,7 @@ if (UNIX)
     FORCE
   )
   SET(HTML_INSTALL_DIR
-    "${DATA_INSTALL_PREFIX}/doc/HTML"
+	  "${DATA_INSTALL_PREFIX}/doc/${_PROJECT_NAME}/HTML"
     CACHE PATH "The HTML install dir for documentation (default data/doc/html)"
     FORCE
   )
@@ -97,7 +97,7 @@ if (UNIX)
     FORCE
   )
   SET(MAN_INSTALL_DIR
-    "${SHARE_INSTALL_PREFIX}/man"
+    "${CMAKE_INSTALL_PREFIX}/man"
     CACHE PATH "The ${_PROJECT_NAME} man install dir (default prefix/man)"
     FORCE
   )
