--- simdjson/simdjson.h.orig	2022-04-21 05:39:10 UTC
+++ simdjson/simdjson.h
@@ -17200,7 +17200,7 @@ simdjson_unused simdjson_warn_unused simdjson_really_i
 #ifndef SIMDJSON_PPC64_NUMBERPARSING_H
 #define SIMDJSON_PPC64_NUMBERPARSING_H
 
-#include <byteswap.h>
+#include <sys/endian.h>
 
 namespace simdjson {
 namespace ppc64 {
@@ -17213,7 +17213,7 @@ parse_eight_digits_unrolled(const uint8_t *chars) {
   uint64_t val;
   std::memcpy(&val, chars, sizeof(uint64_t));
 #ifdef __BIG_ENDIAN__
-  val = bswap_64(val);
+  val = bswap64(val);
 #endif
   val = (val & 0x0F0F0F0F0F0F0F0F) * 2561 >> 8;
   val = (val & 0x00FF00FF00FF00FF) * 6553601 >> 16;
