--- libswfdec/mpglib/clipconv_f32_s16.h.orig	Sat Apr  5 15:54:30 2003
+++ libswfdec/mpglib/clipconv_f32_s16.h	Sat Apr  5 15:57:36 2003
@@ -34,7 +34,7 @@
 //#include <sl_altivec.h>
 #define f32 float
 #define s16 short
-#define HAVE_IEEE754_H
+#undef HAVE_IEEE754_H
 
 
 /* storage class */
