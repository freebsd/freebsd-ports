--- ./cmake/modules/FindWPG.cmake.orig	2011-03-25 01:38:36.660731693 +0100
+++ ./cmake/modules/FindWPG.cmake	2011-03-25 01:40:49.690727037 +0100
@@ -18,11 +18,10 @@
 
   IF (NOT WIN32)
     INCLUDE(FindPkgConfig)
-    pkg_check_modules(LIBWPG libwpg-0.1)
     pkg_check_modules(LIBWPG libwpg-0.2)
   ENDIF (NOT WIN32)
 
-  FIND_LIBRARY(LIBWPG_STREAM_LIBRARIES NAMES libwpg-stream-0.1 wpg-stream-0.1 libwpd-stream-0.9 wpd-stream-0.9
+  FIND_LIBRARY(LIBWPG_STREAM_LIBRARIES NAMES libwpd-stream-0.9 wpd-stream-0.9
     PATHS
     ${LIBWPG_LIBRARIES}
     )
@@ -30,7 +29,7 @@
   FIND_PATH(LIBWPG_INCLUDE_DIR libwpg/libwpg.h
     PATHS
     ${LIBWPG_INCLUDE_DIRS}
-    PATH_SUFFIXES libwpg
+    PATH_SUFFIXES libwpg-0.2
     )
 
   IF (LIBWPG_INCLUDE_DIR AND LIBWPG_LIBRARIES)
