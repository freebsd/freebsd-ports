--- cmake/modules/FindFreetype.cmake.orig	2013-12-13 12:47:10.000000000 +0100
+++ cmake/modules/FindFreetype.cmake	2013-12-13 12:47:42.000000000 +0100
@@ -12,7 +12,7 @@
 
 # Include dir
 find_path(Freetype_INCLUDE_DIR
-  NAMES freetype/freetype.h
+  NAMES freetype.h
   PATHS ${Freetype_PKGCONF_INCLUDE_DIRS}
   PATH_SUFFIXES freetype2
 )
