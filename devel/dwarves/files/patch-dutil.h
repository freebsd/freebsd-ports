--- dutil.h.orig	2020-08-21 14:53:52 UTC
+++ dutil.h
@@ -28,6 +28,9 @@
 #define __pure __attribute__ ((pure))
 #endif
 
+#ifdef roundup
+#undef roundup
+#endif
 #define roundup(x,y) ((((x) + ((y) - 1)) / (y)) * (y))
 
 static inline __attribute__((const)) bool is_power_of_2(unsigned long n)
@@ -35,6 +38,7 @@ static inline __attribute__((const)) bool is_power_of_
         return (n != 0 && ((n & (n - 1)) == 0));
 }
 
+#ifndef __FreeBSD__
 /**
  * fls - find last (most-significant) bit set
  * @x: the word to search
@@ -46,6 +50,7 @@ static __always_inline int fls(int x)
 {
 	return x ? sizeof(x) * 8 - __builtin_clz(x) : 0;
 }
+#endif /* !__FreeBSD__ */
 
 /**
  * fls64 - find last set bit in a 64-bit word
