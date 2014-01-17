--- CMakeModules/FindFreeType.cmake.orig	2013-12-24 19:18:24.000000000 +0100
+++ CMakeModules/FindFreeType.cmake	2013-12-24 19:19:27.000000000 +0100
@@ -24,18 +24,18 @@
 # wants explicit full paths and this trickery doesn't work too well.
 # I'm going to attempt to cut out the middleman and hope 
 # everything still works.
-FIND_PATH(FREETYPE_INCLUDE_DIR_ft2build ft2build.h 
+FIND_PATH(FREETYPE_INCLUDE_DIR_ft2build freetype2/ft2build.h 
   PATHS
   $ENV{FREETYPE_DIR}
   NO_DEFAULT_PATH
   PATH_SUFFIXES include    
 )
-FIND_PATH(FREETYPE_INCLUDE_DIR_ft2build ft2build.h 
+FIND_PATH(FREETYPE_INCLUDE_DIR_ft2build freetype2/ft2build.h 
   PATHS ${CMAKE_PREFIX_PATH} # Unofficial: We are proposing this.
   NO_DEFAULT_PATH
   PATH_SUFFIXES include
 )
-FIND_PATH(FREETYPE_INCLUDE_DIR_ft2build ft2build.h 
+FIND_PATH(FREETYPE_INCLUDE_DIR_ft2build freetype2/ft2build.h 
   PATHS
   /usr/local
   /usr
@@ -51,16 +51,16 @@
   PATH_SUFFIXES include
 )
 
-FIND_PATH(FREETYPE_INCLUDE_DIR_freetype2 freetype/config/ftheader.h 
+FIND_PATH(FREETYPE_INCLUDE_DIR_freetype2 config/ftheader.h 
   $ENV{FREETYPE_DIR}/include/freetype2
   NO_DEFAULT_PATH
 )
-FIND_PATH(FREETYPE_INCLUDE_DIR_freetype2 freetype/config/ftheader.h 
+FIND_PATH(FREETYPE_INCLUDE_DIR_freetype2 config/ftheader.h 
   PATHS ${CMAKE_PREFIX_PATH} # Unofficial: We are proposing this.
   NO_DEFAULT_PATH
   PATH_SUFFIXES include/freetype2
 )
-FIND_PATH(FREETYPE_INCLUDE_DIR_freetype2 freetype/config/ftheader.h 
+FIND_PATH(FREETYPE_INCLUDE_DIR_freetype2 config/ftheader.h 
   /usr/local/include/freetype2
   /usr/include/freetype2
   /usr/local/X11R6/include/freetype2
