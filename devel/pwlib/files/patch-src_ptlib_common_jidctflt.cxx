--- src/ptlib/common/jidctflt.cxx.orig	Wed Apr  5 07:08:00 2006
+++ src/ptlib/common/jidctflt.cxx	Wed Apr  5 07:08:08 2006
@@ -97,7 +97,8 @@
 #define DEQUANTIZE(coef,quantval)  (((FAST_FLOAT) (coef)) * (quantval))
 
 
-#if defined(__GNUC__) && (__GNUC__ >= 3) && (defined(__i686__) || defined(__x86_64__)) && (!defined(P_64BIT)) && (!defined(__MACOSX__))
+/* asm doesn't compile properly... avoid using */
+#if 0 
 
 static inline unsigned char descale_and_clamp(int x, int shift)
 {
