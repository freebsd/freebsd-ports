--- ./cmake/modules/FindWPD.cmake.orig	2010-03-30 13:10:16.507260418 +1100
+++ ./cmake/modules/FindWPD.cmake	2010-03-30 13:09:54.253774780 +1100
@@ -25,9 +25,10 @@
 endif(NOT WIN32)
 
   FIND_PATH(WPD_INCLUDE_DIR libwpd/libwpd.h
-    ${_WPDIncDir}
-    /usr/include/libwpd-0.8
-  )
+     PATHS
+   ${_WPDIncDir}
+     PATH_SUFFIXES libwpd-0.8
+ )
 
   FIND_LIBRARY(WPD_LIBRARIES NAMES wpd-0.8
     PATHS
