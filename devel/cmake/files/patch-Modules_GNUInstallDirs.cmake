--- Modules/GNUInstallDirs.cmake.orig	2018-11-06 09:52:09 UTC
+++ Modules/GNUInstallDirs.cmake
@@ -276,14 +276,12 @@ _GNUInstallDirs_cache_path(CMAKE_INSTALL_DATAROOTDIR "
 _GNUInstallDirs_cache_path_fallback(CMAKE_INSTALL_DATADIR "${CMAKE_INSTALL_DATAROOTDIR}"
   "Read-only architecture-independent data (DATAROOTDIR)")
 
+_GNUInstallDirs_cache_path_fallback(CMAKE_INSTALL_INFODIR "${CMAKE_INSTALL_DATAROOTDIR}/info"
+    "Info documentation (DATAROOTDIR/info)")
 if(CMAKE_SYSTEM_NAME MATCHES "^(.*BSD|DragonFly)$")
-  _GNUInstallDirs_cache_path_fallback(CMAKE_INSTALL_INFODIR "info"
-    "Info documentation (info)")
   _GNUInstallDirs_cache_path_fallback(CMAKE_INSTALL_MANDIR "man"
     "Man documentation (man)")
 else()
-  _GNUInstallDirs_cache_path_fallback(CMAKE_INSTALL_INFODIR "${CMAKE_INSTALL_DATAROOTDIR}/info"
-    "Info documentation (DATAROOTDIR/info)")
   _GNUInstallDirs_cache_path_fallback(CMAKE_INSTALL_MANDIR "${CMAKE_INSTALL_DATAROOTDIR}/man"
     "Man documentation (DATAROOTDIR/man)")
 endif()
