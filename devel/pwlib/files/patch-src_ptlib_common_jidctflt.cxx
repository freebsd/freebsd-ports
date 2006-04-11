--- src/ptlib/common/jidctflt.cxx.orig	Wed Apr  5 07:08:00 2006
+++ src/ptlib/common/jidctflt.cxx	Wed Apr  5 07:08:08 2006
@@ -80,7 +80,8 @@
 
 #define DEQUANTIZE(coef,quantval)  (((FAST_FLOAT) (coef)) * (quantval))
 
-#if defined(__GNUC__) && (defined(__i686__) || defined(__x86_64__))
+/* asm doesn't compile properly... avoid using */
+#if 0 

 static inline unsigned char descale_and_clamp(int x, int shift)
 {
