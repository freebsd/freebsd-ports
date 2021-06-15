--- include/simdjson/ppc64/numberparsing.h.orig	2021-06-13 11:45:59 UTC
+++ include/simdjson/ppc64/numberparsing.h
@@ -1,7 +1,7 @@
 #ifndef SIMDJSON_PPC64_NUMBERPARSING_H
 #define SIMDJSON_PPC64_NUMBERPARSING_H
 
-#include <byteswap.h>
+#include <sys/endian.h>
 
 namespace simdjson {
 namespace SIMDJSON_IMPLEMENTATION {
@@ -14,7 +14,7 @@ parse_eight_digits_unrolled(const uint8_t *chars) {
   uint64_t val;
   std::memcpy(&val, chars, sizeof(uint64_t));
 #ifdef __BIG_ENDIAN__
-  val = bswap_64(val);
+  val = bswap64(val);
 #endif
   val = (val & 0x0F0F0F0F0F0F0F0F) * 2561 >> 8;
   val = (val & 0x00FF00FF00FF00FF) * 6553601 >> 16;
