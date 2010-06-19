--- ./cmake/modules/FindWPD.cmake.orig	2010-03-30 13:10:16.507260418 +1100
+++ ./cmake/modules/FindWPD.cmake	2010-03-30 13:09:54.253774780 +1100
@@ -24,7 +24,7 @@
 
   FIND_PATH(WPD_INCLUDE_DIR libwpd/libwpd.h
     ${WPD_INCLUDE_DIR}
-    /usr/include/libwpd-0.8
+    PATH_SUFFIXES libwpd-0.8
   )
 
 
