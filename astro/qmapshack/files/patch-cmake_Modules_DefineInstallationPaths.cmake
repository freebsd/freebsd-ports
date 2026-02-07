--- cmake/Modules/DefineInstallationPaths.cmake.orig	2025-07-04 12:38:57 UTC
+++ cmake/Modules/DefineInstallationPaths.cmake
@@ -51,7 +51,7 @@ if (UNIX)
     CACHE PATH "The parent directory where applications can install their data (default prefix/share/${_PROJECT_NAME})"
   )
   SET(HTML_INSTALL_DIR
-    "${DATA_INSTALL_PREFIX}/doc/HTML"
+	  "${DATA_INSTALL_PREFIX}/doc/${_PROJECT_NAME}/HTML"
     CACHE PATH "The HTML install dir for documentation (default data/doc/html)"
   )
   SET(ICON_INSTALL_DIR
@@ -82,7 +82,7 @@ if (UNIX)
     CACHE PATH "The ${_PROJECT_NAME} sysconfig install dir (default prefix/etc)"
   )
   SET(MAN_INSTALL_DIR
-    "${SHARE_INSTALL_PREFIX}/man"
+    "${CMAKE_INSTALL_PREFIX}/share/man"
     CACHE PATH "The ${_PROJECT_NAME} man install dir (default prefix/man)"
   )
   SET(INFO_INSTALL_DIR
