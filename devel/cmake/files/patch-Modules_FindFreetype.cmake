In the 2.5.1 release of freetype most of the headers where moved from 
freetype2/freetype/* -> freetype2/*. So we need to update the detection
rules to take this into account.

http://public.kitware.com/Bug/view.php?id=14601

--- Modules/FindFreetype.cmake.orig	2013-12-13 11:15:05.000000000 +0100
+++ Modules/FindFreetype.cmake	2013-12-13 11:15:39.000000000 +0100
@@ -56,7 +56,7 @@
   PATH_SUFFIXES include/freetype2 include
 )
 
-find_path(FREETYPE_INCLUDE_DIR_freetype2 freetype/config/ftheader.h
+find_path(FREETYPE_INCLUDE_DIR_freetype2 config/ftheader.h
   HINTS
     ENV FREETYPE_DIR
   PATHS
@@ -91,8 +91,8 @@
 endif()
 set(FREETYPE_LIBRARIES "${FREETYPE_LIBRARY}")
 
-if(FREETYPE_INCLUDE_DIR_freetype2 AND EXISTS "${FREETYPE_INCLUDE_DIR_freetype2}/freetype/freetype.h")
-    file(STRINGS "${FREETYPE_INCLUDE_DIR_freetype2}/freetype/freetype.h" freetype_version_str
+if(FREETYPE_INCLUDE_DIR_freetype2 AND EXISTS "${FREETYPE_INCLUDE_DIR_freetype2}/freetype.h")
+    file(STRINGS "${FREETYPE_INCLUDE_DIR_freetype2}/freetype.h" freetype_version_str
          REGEX "^#[\t ]*define[\t ]+FREETYPE_(MAJOR|MINOR|PATCH)[\t ]+[0-9]+$")
 
     unset(FREETYPE_VERSION_STRING)
