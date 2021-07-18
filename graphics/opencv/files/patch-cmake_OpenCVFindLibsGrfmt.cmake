--- cmake/OpenCVFindLibsGrfmt.cmake.orig	2021-07-18 11:13:32 UTC
+++ cmake/OpenCVFindLibsGrfmt.cmake
@@ -228,9 +228,9 @@ if(WITH_PNG)
     include(FindPNG)
     if(PNG_FOUND)
       include(CheckIncludeFile)
-      check_include_file("${PNG_PNG_INCLUDE_DIR}/libpng/png.h" HAVE_LIBPNG_PNG_H)
+      check_include_file("${PNG_PNG_INCLUDE_DIR}/libpng16/png.h" HAVE_LIBPNG_PNG_H)
       if(HAVE_LIBPNG_PNG_H)
-        ocv_parse_header("${PNG_PNG_INCLUDE_DIR}/libpng/png.h" PNG_VERSION_LINES PNG_LIBPNG_VER_MAJOR PNG_LIBPNG_VER_MINOR PNG_LIBPNG_VER_RELEASE)
+        ocv_parse_header("${PNG_PNG_INCLUDE_DIR}/libpng16/png.h" PNG_VERSION_LINES PNG_LIBPNG_VER_MAJOR PNG_LIBPNG_VER_MINOR PNG_LIBPNG_VER_RELEASE)
       else()
         ocv_parse_header("${PNG_PNG_INCLUDE_DIR}/png.h" PNG_VERSION_LINES PNG_LIBPNG_VER_MAJOR PNG_LIBPNG_VER_MINOR PNG_LIBPNG_VER_RELEASE)
       endif()
