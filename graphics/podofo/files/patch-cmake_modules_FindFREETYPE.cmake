--- cmake/modules/FindFREETYPE.cmake.orig	2013-12-23 19:53:54.000000000 +0200
+++ cmake/modules/FindFREETYPE.cmake	2013-12-23 19:54:05.000000000 +0200
@@ -12,14 +12,14 @@
 
 SET(FREETYPE_FIND_QUIETLY 1)
 
-FIND_PATH(FREETYPE_INCLUDE_DIR_FT2BUILD ft2build.h
+FIND_PATH(FREETYPE_INCLUDE_DIR_FT2BUILD freetype2/ft2build.h
   /usr/include/
   /usr/local/include/
   /usr/X11/include/
   NO_CMAKE_SYSTEM_PATH
 )
 
-FIND_PATH(FREETYPE_INCLUDE_DIR_FTHEADER freetype/config/ftheader.h
+FIND_PATH(FREETYPE_INCLUDE_DIR_FTHEADER config/ftheader.h
   /usr/include/freetype2
   /usr/local/include/freetype2
   /usr/X11/include/freetype2
