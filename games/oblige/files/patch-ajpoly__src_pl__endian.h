--- ajpoly_src/pl_endian.h.orig	2023-07-31 15:43:19 UTC
+++ ajpoly_src/pl_endian.h
@@ -57,10 +57,7 @@ static inline u16_t UT_Swap16(u16_t x)
 #elif defined(__GNUC__) && (defined(__powerpc__) || defined(__ppc__))
 static inline u16_t UT_Swap16(u16_t x)
 {
-  u16_t result;
-
-  __asm__("rlwimi %0,%2,8,16,23" : "=&r" (result) : "0" (x >> 8), "r" (x));
-  return result;
+  return __builtin_bswap16(x);
 }
 #else
 static inline u16_t UT_Swap16(u16_t x) {
