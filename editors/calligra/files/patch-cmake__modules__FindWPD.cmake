--- ./cmake/modules/FindWPD.cmake.orig	2011-10-16 07:29:58.807077221 -0700
+++ ./cmake/modules/FindWPD.cmake	2011-10-16 07:30:23.717073061 -0700
@@ -19,17 +19,13 @@
 #else (WPD_INCLUDE_DIR AND WPD_LIBRARIES)
 if(NOT WIN32)
   INCLUDE(FindPkgConfig)
-  pkg_check_modules(WPD libwpd-0.8)
   pkg_check_modules(WPD libwpd-0.9)
 endif(NOT WIN32)
 
   FIND_PATH(WPD_INCLUDE_DIR libwpd/libwpd.h
     PATHS
 	  ${WPD_INCLUDE_DIR}
-      /usr/include/libwpd-0.8
-      /usr/include/libwpd-0.9
 	PATH_SUFFIXES
-	  libwpd-0.8
 	  libwpd-0.9
   )
 
