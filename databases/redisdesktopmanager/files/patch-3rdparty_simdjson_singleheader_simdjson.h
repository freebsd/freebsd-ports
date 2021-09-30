--- 3rdparty/simdjson/singleheader/simdjson.h.orig	2021-09-30 06:08:20 UTC
+++ 3rdparty/simdjson/singleheader/simdjson.h
@@ -15748,7 +15748,11 @@ simdjson_unused simdjson_warn_unused simdjson_really_i
 #ifndef SIMDJSON_PPC64_NUMBERPARSING_H
 #define SIMDJSON_PPC64_NUMBERPARSING_H
 
+#ifdef linux
 #include <byteswap.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#endif
 
 namespace simdjson {
 namespace ppc64 {
