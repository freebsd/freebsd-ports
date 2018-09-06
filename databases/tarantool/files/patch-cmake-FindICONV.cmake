--- cmake/FindICONV.cmake.orig	2018-09-06 16:31:05 UTC
+++ cmake/FindICONV.cmake
@@ -4,14 +4,8 @@
 # ICONV_LIBRARIES
 #
 
-if (TARGET_OS_LINUX)
+if (TARGET_OS_FREEBSD OR TARGET_OS_LINUX)
     set(ICONV_LIBRARY "")
-else()
-    find_library(ICONV_LIBRARY iconv)
-    if(NOT ICONV_LIBRARY)
-        message(WARNING "iconv library not found")
-        set(ICONV_LIBRARY "")
-    endif()
 endif()
 find_path(ICONV_INCLUDE_DIR iconv.h)
 if(NOT ICONV_INCLUDE_DIR)
