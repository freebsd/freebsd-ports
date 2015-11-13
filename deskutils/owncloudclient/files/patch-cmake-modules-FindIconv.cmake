--- cmake/modules/FindIconv.cmake.orig	2015-07-09 17:51:37 UTC
+++ cmake/modules/FindIconv.cmake
@@ -36,9 +36,7 @@ find_library(ICONV_LIBRARY
 )
 
 if (ICONV_LIBRARY)
-    get_filename_component(_ICONV_NAME ${ICONV_LIBRARY} NAME)
-    get_filename_component(_ICONV_PATH ${ICONV_LIBRARY} PATH)
-    check_library_exists(${_ICONV_NAME} iconv ${_ICONV_PATH} HAVE_ICONV)
+    set(HAVE_ICONV TRUE)
 else()
     check_function_exists(iconv HAVE_ICONV)
 endif()
