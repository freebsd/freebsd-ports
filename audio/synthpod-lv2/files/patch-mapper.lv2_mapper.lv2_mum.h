--- mapper.lv2/mapper.lv2/mum.h.orig	2020-07-04 11:56:10 UTC
+++ mapper.lv2/mapper.lv2/mum.h
@@ -110,7 +110,7 @@ _mum (uint64_t v, uint64_t p) {
      function doing 128x128->128 bit multiplication.  The function is
      very slow.  */
   lo = v * p, hi;
-  asm ("umulh %0, %1, %2" : "=r" (hi) : "r" (v), "r" (p));
+  __asm__ ("umulh %0, %1, %2" : "=r" (hi) : "r" (v), "r" (p));
 #else
   __uint128_t r = (__uint128_t) v * (__uint128_t) p;
   hi = (uint64_t) (r >> 64);
