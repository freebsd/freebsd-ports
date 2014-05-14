--- cmake/FindFreetype.cmake.orig	2013-12-07 13:37:10.000000000 +0400
+++ cmake/FindFreetype.cmake	2014-05-14 02:27:04.594193598 +0400
@@ -3,8 +3,8 @@
 ################################################################################
 include(FindPackageHandleStandardArgs)
 
-find_path(FREETYPE_H_PATH_ft2build NAMES ft2build.h)
-find_path(FREETYPE_H_PATH_ftconfig NAMES freetype/config/ftconfig.h PATH_SUFFIXES freetype2)
+find_path(FREETYPE_H_PATH_ft2build NAMES ft2build.h PATH_SUFFIXES freetype2)
+find_path(FREETYPE_H_PATH_ftconfig NAMES config/ftconfig.h PATH_SUFFIXES freetype2)
 find_library(FREETYPE_LIB NAMES freetype2 freetype libfreetype PATH_SUFFIXES dynamic)
 find_library(FREETYPE_LIB_DBG NAMES freetype_d libfreetype_d PATH_SUFFIXES dynamic)
 mark_as_advanced(FREETYPE_H_PATH_ft2build FREETYPE_H_PATH_ftconfig FREETYPE_LIB FREETYPE_LIB_DBG)
