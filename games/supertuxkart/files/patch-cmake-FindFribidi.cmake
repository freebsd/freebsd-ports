--- cmake/FindFribidi.cmake.orig	2013-03-13 08:03:26.000000000 +0400
+++ cmake/FindFribidi.cmake	2013-11-28 09:33:04.134268507 +0400
@@ -18,7 +18,15 @@
     set(FRIBIDI_FOUND 1)
 elseif(UNIX)
     include(FindPkgConfig)
-    pkg_check_modules(FRIBIDI fribidi)
+    pkg_check_modules(PC_FRIBIDI fribidi)
+    find_path(FRIBIDI_INCLUDE_DIR NAMES fribidi/fribidi.h HINTS ${PC_FRIBIDI_INCLUDE_DIRS})
+    find_library(FRIBIDI_LIBRARY NAMES fribidi HINTS ${PC_FRIBIDI_LIBRARY_DIRS})
+
+    include(FindPackageHandleStandardArgs)
+    find_package_handle_standard_args(Fribidi DEFAULT_MSG FRIBIDI_INCLUDE_DIR FRIBIDI_LIBRARY)
+
+    set(FRIBIDI_INCLUDE_DIRS ${FRIBIDI_INCLUDE_DIR})
+    set(FRIBIDI_LIBRARIES ${FRIBIDI_LIBRARY})
 else()
     set(FRIBIDI_FOUND 0)
 endif()
