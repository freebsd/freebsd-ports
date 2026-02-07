--- src/sys_endian.h.orig	2020-12-18 15:02:12 UTC
+++ src/sys_endian.h
@@ -58,7 +58,7 @@ static inline u16_t UT_Swap16(u16_t x)
   __asm__("xchgb %b0,%h0" : "=Q" (x) :  "0" (x));
   return x;
 }
-#elif defined(__GNUC__) && (defined(__powerpc__) || defined(__ppc__))
+#elif defined(__GNUC__) && !defined(__clang__) && (defined(__powerpc__) || defined(__ppc__))
 static inline u16_t UT_Swap16(u16_t x)
 {
   u16_t result;
