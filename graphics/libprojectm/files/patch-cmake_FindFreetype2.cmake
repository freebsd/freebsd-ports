--- cmake/FindFreetype2.cmake.orig	2013-12-24 19:02:55.000000000 +0100
+++ cmake/FindFreetype2.cmake	2013-12-24 19:03:21.000000000 +0100
@@ -67,7 +67,7 @@
       NO_DEFAULT_PATH
 )
 
-FIND_PATH(FREETYPE2_FT2BUILD ft2build.h
+FIND_PATH(FREETYPE2_FT2BUILD freetype2/ft2build.h
        ${ADDITIONAL_INCLUDE_PATH}
       /usr/include
       /usr/X11/include
