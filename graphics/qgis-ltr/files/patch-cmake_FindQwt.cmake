--- cmake/FindQwt.cmake.orig	2020-08-28 05:25:49 UTC
+++ cmake/FindQwt.cmake
@@ -32,6 +32,7 @@ endif()
 FIND_PATH(QWT_INCLUDE_DIR NAMES qwt.h PATHS
   "${_qwt_fw}/Headers"
   /usr/include
+  /usr/include/qt5
   /usr/local/include
   /usr/local/include/qt5
   "$ENV{LIB_DIR}/include"
