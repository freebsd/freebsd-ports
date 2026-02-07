--- brunsli.cmake.orig	2019-10-28 09:56:51 UTC
+++ brunsli.cmake
@@ -57,7 +57,7 @@ add_library(brunslidec-static STATIC
   ${BRUNSLI_DEC_HEADERS}
 )
 target_link_libraries(brunslidec-static PRIVATE
-  brotlidec-static
+  brotlidec
   brunslicommon-static
 )
 
@@ -66,7 +66,7 @@ add_library(brunslienc-static STATIC
   ${BRUNSLI_ENC_HEADERS}
 )
 target_link_libraries(brunslienc-static PRIVATE
-  brotlienc-static
+  brotlienc
   brunslicommon-static
 )
 
