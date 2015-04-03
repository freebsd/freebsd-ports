--- cmake/FindLibiconv.cmake.orig	2015-04-03 02:44:55.321687654 +0000
+++ cmake/FindLibiconv.cmake	2015-04-03 02:46:05.734216729 +0000
@@ -30,7 +30,7 @@ set(LIBICONV_LIB_FOUND FALSE)
 
 if(LIBICONV_INCLUDE_DIR)
   include(CheckFunctionExists)
-  check_function_exists(iconv_open LIBICONV_LIBC_HAS_ICONV_OPEN)
+  set(LIBICONV_LIBC_HAS_ICONV_OPEN FALSE)
 
   if (LIBICONV_LIBC_HAS_ICONV_OPEN)
     set(LIBICONV_LIBRARIES)
