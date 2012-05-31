--- ./cmake/modules/FindWPG.cmake.orig	2011-10-16 07:30:32.257075896 -0700
+++ ./cmake/modules/FindWPG.cmake	2011-10-16 07:32:34.927100360 -0700
@@ -18,7 +18,6 @@
 
   IF (NOT WIN32)
     INCLUDE(FindPkgConfig)
-    pkg_check_modules(LIBWPG libwpg-0.1)
     pkg_check_modules(LIBWPG libwpg-0.2)
     IF(LIBWPG_FOUND)
         SET(LIBWPG_LIBRARY ${LIBWPG_LIBRARIES})
@@ -32,12 +31,8 @@
 
   FIND_LIBRARY(LIBWPG_STREAM_LIBRARY
       NAMES 
-	  libwpg-stream-0.1 
-	  wpg-stream-0.1 
 	  libwpd-stream-0.9 
 	  wpd-stream-0.9
-	  libwpd-stream
-	  wpd-stream
       PATHS
           ${LIBWPG_LIBRARIES}
   )
@@ -45,7 +40,7 @@
   FIND_PATH(LIBWPG_INCLUDE_DIR libwpg/libwpg.h
       PATHS
       ${LIBWPG_INCLUDE_DIRS}
-      PATH_SUFFIXES libwpg-0.1 libwpg-0.2 libwpg 
+      PATH_SUFFIXES libwpg-0.2
   )
 
   SET(LIBWPG_LIBRARIES ${LIBWPG_LIBRARY} ${LIBWPG_STREAM_LIBRARY})
