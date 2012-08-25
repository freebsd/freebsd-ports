--- ./cmake/modules/FindWPG.cmake.orig	2012-07-17 01:34:40.838916621 +0200
+++ ./cmake/modules/FindWPG.cmake	2012-07-17 01:36:33.058951606 +0200
@@ -28,7 +28,7 @@
 
     FIND_LIBRARY(LIBWPG_STREAM_LIBRARY
         NAMES
-            libwpd-stream-0.9 wpd-stream-0.9 libwpd-stream wpd-stream
+            libwpd-stream-0.9 wpd-stream-0.9
         PATHS
             ${LIBWPG_LIBRARIES}
     )
@@ -36,7 +36,7 @@
     FIND_PATH(LIBWPG_INCLUDE_DIR libwpg/libwpg.h
         PATHS
             ${LIBWPG_INCLUDE_DIRS}
-        PATH_SUFFIXES libwpg-0.2 libwpg
+        PATH_SUFFIXES libwpg-0.2
     )
 
     SET(LIBWPG_LIBRARIES ${LIBWPG_LIBRARY} ${LIBWPG_STREAM_LIBRARY})
