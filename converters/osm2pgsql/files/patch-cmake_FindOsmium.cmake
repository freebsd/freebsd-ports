--- cmake/FindOsmium.cmake.orig	2017-04-13 20:58:25 UTC
+++ cmake/FindOsmium.cmake
@@ -151,8 +151,8 @@ list(APPEND OSMIUM_LIBRARIES
 #----------------------------------------------------------------------
 # Component 'geos'
 if(Osmium_USE_GEOS)
-    find_path(GEOS_INCLUDE_DIR geos/geom.h)
-    find_library(GEOS_LIBRARY NAMES geos)
+    find_path(GEOS_INCLUDE_DIR geos35/geos/geom.h)
+    find_library(GEOS_LIBRARY NAMES geos35)
 
     list(APPEND OSMIUM_EXTRA_FIND_VARS GEOS_INCLUDE_DIR GEOS_LIBRARY)
     if(GEOS_INCLUDE_DIR AND GEOS_LIBRARY)
