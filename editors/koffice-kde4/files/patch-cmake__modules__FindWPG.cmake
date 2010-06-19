--- ./cmake/modules/FindWPG.cmake.orig	2010-03-30 00:05:52.000000000 +1100
+++ ./cmake/modules/FindWPG.cmake	2010-03-30 13:07:46.392743489 +1100
@@ -29,7 +29,7 @@
   FIND_PATH(LIBWPG_INCLUDE_DIR libwpg/libwpg.h
     PATHS
     ${LIBWPG_INCLUDE_DIRS}
-    PATH_SUFFIXES libwpg
+    PATH_SUFFIXES libwpg-0.1
     )
 
   IF (LIBWPG_INCLUDE_DIR AND LIBWPG_LIBRARIES)
