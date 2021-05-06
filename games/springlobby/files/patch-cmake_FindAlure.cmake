--- cmake/FindAlure.cmake.orig	2019-11-24 14:00:54 UTC
+++ cmake/FindAlure.cmake
@@ -14,13 +14,8 @@
 
 find_path(ALURE_INCLUDE_DIR
     NAMES
-      alure.h
-      PATH_SUFFIXES AL OpenAL
-    PATHS
-      /usr/include
-      /usr/local/include
-      /opt/local/include
-      /sw/include
+      AL/alure.h
+      OpenAL/alure.h
   )
 
 #IF (NOT ALURE_MIN_VERSION)
@@ -42,12 +37,7 @@ find_path(ALURE_INCLUDE_DIR
 
   find_library(ALURE_LIBRARY
     NAMES
-      alure alure 32 ALURE32-static ALURE32
-    PATHS
-      /usr/lib
-      /usr/local/lib
-      /opt/local/lib
-      /sw/lib
+      alure
   )
 
   set(ALURE_INCLUDE_DIRS
