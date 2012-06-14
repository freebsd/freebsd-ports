--- CMake/FindOpenJPEG.cmake.orig	2012-06-14 12:47:50.000000000 +0200
+++ CMake/FindOpenJPEG.cmake	2012-06-14 12:47:59.000000000 +0200
@@ -21,7 +21,6 @@
 # Try first to locate a cmake config file
 FIND_PACKAGE(OpenJPEG QUIET NO_MODULE)
 
-if( NOT OpenJPEG_DIR )
 SET(OPENJPEG_MAJOR_VERSION 1) # FIXME ?
 FIND_PATH(OPENJPEG_INCLUDE_DIR
   NAMES openjpeg.h #openjpeg-1.0/openjpeg.h
@@ -50,4 +49,3 @@
   OPENJPEG_LIBRARY
   OPENJPEG_INCLUDE_DIR
   )
-endif()
