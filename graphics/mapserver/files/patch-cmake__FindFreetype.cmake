--- cmake/FindFreetype.cmake.orig	2013-12-23 20:00:03.000000000 +0200
+++ cmake/FindFreetype.cmake	2013-12-23 20:00:14.000000000 +0200
@@ -41,7 +41,7 @@
 # wants explicit full paths and this trickery doesn't work too well.
 # I'm going to attempt to cut out the middleman and hope 
 # everything still works.
-FIND_PATH(FREETYPE_INCLUDE_DIR_ft2build ft2build.h 
+FIND_PATH(FREETYPE_INCLUDE_DIR_ft2build freetype2/ft2build.h 
   HINTS
   $ENV{FREETYPE_DIR}
   PATH_SUFFIXES include
@@ -54,7 +54,7 @@
   /usr/freeware/include
 )
 
-FIND_PATH(FREETYPE_INCLUDE_DIR_freetype2 freetype/config/ftheader.h 
+FIND_PATH(FREETYPE_INCLUDE_DIR_freetype2 config/ftheader.h 
   HINTS
   $ENV{FREETYPE_DIR}/include/freetype2
   PATHS
