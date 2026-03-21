--- dutil.h.orig	2024-10-01 14:51:57 UTC
+++ dutil.h
@@ -29,6 +29,9 @@
 #define __pure __attribute__ ((pure))
 #endif
 
+#ifdef roundup
+#undef roundup
+#endif
 #define roundup(x,y) ((((x) + ((y) - 1)) / (y)) * (y))
 
 #ifndef DW_TAG_LLVM_annotation
@@ -40,6 +43,7 @@ static inline __attribute__((const)) bool is_power_of_
         return (n != 0 && ((n & (n - 1)) == 0));
 }
 
+#ifndef __FreeBSD__
 /**
  * fls - find last (most-significant) bit set
  * @x: the word to search
@@ -51,6 +55,7 @@ static __always_inline int fls(int x)
 {
 	return x ? sizeof(x) * 8 - __builtin_clz(x) : 0;
 }
+#endif /* !__FreeBSD__ */
 
 /**
  * fls64 - find last set bit in a 64-bit word
