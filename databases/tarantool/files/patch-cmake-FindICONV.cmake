--- cmake/FindICONV.cmake.orig	2018-10-12 19:53:35 UTC
+++ cmake/FindICONV.cmake
@@ -4,7 +4,7 @@
 # ICONV_LIBRARIES
 #
 
-if (TARGET_OS_LINUX)
+if (TARGET_OS_FREEBSD OR TARGET_OS_LINUX)
     set(ICONV_LIBRARY "")
 else()
     find_library(ICONV_LIBRARY iconv)
