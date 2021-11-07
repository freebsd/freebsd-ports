--- 3rdparty/simdjson/singleheader/simdjson.h.orig	2021-09-07 18:36:17 UTC
+++ 3rdparty/simdjson/singleheader/simdjson.h
@@ -17189,7 +17189,11 @@ simdjson_unused simdjson_warn_unused simdjson_really_i
 #ifndef SIMDJSON_PPC64_NUMBERPARSING_H
 #define SIMDJSON_PPC64_NUMBERPARSING_H
 
+#ifdef linux
 #include <byteswap.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#endif
 
 namespace simdjson {
 namespace ppc64 {
@@ -17202,7 +17206,7 @@ parse_eight_digits_unrolled(const uint8_t *chars) {
   uint64_t val;
   std::memcpy(&val, chars, sizeof(uint64_t));
 #ifdef __BIG_ENDIAN__
-  val = bswap_64(val);
+  val = bswap64(val);
 #endif
   val = (val & 0x0F0F0F0F0F0F0F0F) * 2561 >> 8;
   val = (val & 0x00FF00FF00FF00FF) * 6553601 >> 16;
