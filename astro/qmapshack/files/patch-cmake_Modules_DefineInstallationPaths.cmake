diff --git cmake/Modules/DefineInstallationPaths.cmake cmake/Modules/DefineInstallationPaths.cmake
index 66e60854..72cb3642 100644
--- cmake/Modules/DefineInstallationPaths.cmake
+++ cmake/Modules/DefineInstallationPaths.cmake
@@ -20,7 +20,7 @@ if(WIN32)
 else()
     set(BIN_INSTALL_DIR     "${CMAKE_INSTALL_FULL_BINDIR}"                  CACHE PATH "Where the binaries go")
     set(DATA_INSTALL_PREFIX "${CMAKE_INSTALL_FULL_DATAROOTDIR}"             CACHE PATH "Parent directory for application data")
-    set(HTML_INSTALL_DIR    "${CMAKE_INSTALL_FULL_DATAROOTDIR}/doc/HTML"    CACHE PATH "Where the offline help goes")
+    set(HTML_INSTALL_DIR    "${CMAKE_INSTALL_FULL_DATAROOTDIR}/doc/qmapshack/HTML"    CACHE PATH "Where the offline help goes")
     set(ICON_INSTALL_DIR    "${CMAKE_INSTALL_FULL_DATAROOTDIR}/icons"       CACHE PATH "Where the icon theme goes")
     set(XDG_APPS_DIR        "${CMAKE_INSTALL_FULL_DATAROOTDIR}/applications" CACHE PATH "Where the .desktop files go")
     set(MAN_INSTALL_DIR     "${CMAKE_INSTALL_FULL_MANDIR}"                  CACHE PATH "Where the man pages go")
