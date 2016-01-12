--- cmake/FindIconv.cmake.orig	2016-01-10 08:17:50 UTC
+++ cmake/FindIconv.cmake
@@ -48,9 +48,8 @@ find_library(ICONV_LIBRARY
 
 if(ICONV_INCLUDE_PATH)
   if(ICONV_LIBRARY)
-    string(REGEX REPLACE "/[^/]*$" "" ICONV_LIB_PATH "${ICONV_LIBRARY}")
-    check_library_exists(iconv libiconv_open ${ICONV_LIB_PATH} LIBICONV_OPEN_FOUND)
-    check_library_exists(iconv iconv_open ${ICONV_LIB_PATH} ICONV_OPEN_FOUND)
+    check_library_exists("${ICONV_LIBRARY}" libiconv_open "" LIBICONV_OPEN_FOUND)
+    check_library_exists("${ICONV_LIBRARY}" iconv_open "" ICONV_OPEN_FOUND)
     if(LIBICONV_OPEN_FOUND OR ICONV_OPEN_FOUND)
        set(ICONV_FOUND TRUE)
     endif()
