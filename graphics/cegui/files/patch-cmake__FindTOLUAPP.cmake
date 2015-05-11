--- cmake/FindTOLUAPP.cmake.orig	2013-04-29 08:26:36 UTC
+++ cmake/FindTOLUAPP.cmake
@@ -3,9 +3,9 @@
 ################################################################################
 include(FindPackageHandleStandardArgs)
 
-find_path(TOLUAPP_H_PATH NAMES tolua++.h)
-find_library(TOLUAPP_LIB NAMES tolua++5.1 tolua++ toluapp PATH_SUFFIXES dynamic)
-find_library(TOLUAPP_LIB_DBG NAMES tolua++5.1_d tolua++_d toluapp_d PATH_SUFFIXES dynamic)
+find_path(TOLUAPP_H_PATH NAMES tolua++.h PATHS ENV TOLUA_INC) 
+find_library(TOLUAPP_LIB NAMES tolua++-5.1 tolua++ toluapp PATH_SUFFIXES dynamic)
+find_library(TOLUAPP_LIB_DBG NAMES tolua++-5.1_d tolua++_d toluapp_d PATH_SUFFIXES dynamic)
 mark_as_advanced(TOLUAPP_H_PATH TOLUAPP_LIB TOLUAPP_LIB_DBG)
 
 if (WIN32 OR APPLE)
