-- Fall back to system libjpeg when skia was built with skia_use_system_libjpeg_turbo=true.
-- The FreeBSD aseprite-skia port uses system libraries.

--- cmake/FindJpegTurbo.cmake.orig	2026-08-25 10:20:49 UTC
+++ cmake/FindJpegTurbo.cmake
@@ -11,7 +11,15 @@ if(LAF_BACKEND STREQUAL "skia")
 
   find_library(LIBJPEG_TURBO_LIBRARY NAMES libjpeg jpeg
     HINTS "${SKIA_LIBRARY_DIR}" NO_DEFAULT_PATH)
-  set(LIBJPEG_TURBO_INCLUDE_DIRS "${SKIA_DIR}/third_party/externals/libjpeg-turbo")
+
+  if(LIBJPEG_TURBO_LIBRARY)
+    set(LIBJPEG_TURBO_INCLUDE_DIRS "${SKIA_DIR}/third_party/externals/libjpeg-turbo")
+  else()
+    # Fall back to system libjpeg when skia was built with skia_use_system_libjpeg_turbo=true
+    find_library(LIBJPEG_TURBO_LIBRARY NAMES jpeg)
+    find_path(LIBJPEG_TURBO_INCLUDE_DIR NAMES jpeglib.h)
+    set(LIBJPEG_TURBO_INCLUDE_DIRS ${LIBJPEG_TURBO_INCLUDE_DIR})
+  endif()
 
   add_library(libjpeg-turbo STATIC IMPORTED)
   set_target_properties(libjpeg-turbo PROPERTIES
