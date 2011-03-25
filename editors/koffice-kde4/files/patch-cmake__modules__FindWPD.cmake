--- ./cmake/modules/FindWPD.cmake.orig	2011-03-25 01:34:51.930775929 +0100
+++ ./cmake/modules/FindWPD.cmake	2011-03-25 01:37:46.910772674 +0100
@@ -19,13 +19,11 @@
 else (WPD_INCLUDE_DIR AND WPD_LIBRARIES)
 if(NOT WIN32)
   INCLUDE(FindPkgConfig)
-  pkg_check_modules(WPD libwpd-0.8)
   pkg_check_modules(WPD libwpd-0.9)
 endif(NOT WIN32)
 
   FIND_PATH(WPD_INCLUDE_DIR libwpd/libwpd.h
     ${WPD_INCLUDE_DIR}
-    /usr/include/libwpd-0.8
-    /usr/include/libwpd-0.9
+    PATH_SUFFIXES libwpd-0.9
   )
 
