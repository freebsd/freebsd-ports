--- build_files/cmake/Modules/FindOpenColorIO.cmake.orig	2021-12-06 15:16:17 UTC
+++ build_files/cmake/Modules/FindOpenColorIO.cmake
@@ -28,8 +28,8 @@ IF(NOT OPENCOLORIO_ROOT_DIR AND NOT $ENV{OPENCOLORIO_R
 ENDIF()
 
 SET(_opencolorio_FIND_COMPONENTS
-  OpenColorIO
-  yaml-cpp
+  OpenColorIOv1
+  yaml-cpp03
   tinyxml
 )
 
@@ -40,7 +40,7 @@ SET(_opencolorio_SEARCH_DIRS
 
 FIND_PATH(OPENCOLORIO_INCLUDE_DIR
   NAMES
-    OpenColorIO/OpenColorIO.h
+    OpenColorIOv1/OpenColorIO.h
   HINTS
     ${_opencolorio_SEARCH_DIRS}
   PATH_SUFFIXES
