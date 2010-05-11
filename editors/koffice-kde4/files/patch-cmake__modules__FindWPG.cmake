--- ./cmake/modules/FindWPG.cmake.orig	2010-03-30 00:05:52.000000000 +1100
+++ ./cmake/modules/FindWPG.cmake	2010-03-30 13:07:46.392743489 +1100
@@ -22,10 +22,10 @@
     SET(LIBWPG_DEFINITIONS ${_LibWpgCflags})
   ENDIF (NOT WIN32)
   
-  FIND_PATH(LIBWPG_INCLUDE_DIR libwpg-0.1/libwpg/libwpg.h
+  FIND_PATH(LIBWPG_INCLUDE_DIR libwpg/libwpg.h
     PATHS
     ${_LibWpgIncDir}
-    PATH_SUFFIXES libwpg
+    PATH_SUFFIXES libwpg-0.1
     )
 
   FIND_LIBRARY(LIBWPG_LIBRARIES NAMES wpg-0.1 libwpg-0.1
