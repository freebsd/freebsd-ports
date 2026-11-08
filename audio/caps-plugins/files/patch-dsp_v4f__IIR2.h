--- dsp/v4f_IIR2.h.orig	2018-02-01 09:20:59 UTC
+++ dsp/v4f_IIR2.h
@@ -32,8 +32,8 @@ namespace DSP {
 
 namespace DSP {
 
-#ifdef __APPLE__
-inline float exp10f(float f) {return __exp10f(f);}
+#if defined(__APPLE__) || defined(__FreeBSD__)
+inline float exp10f(float f) {return __builtin_exp10f(f);}
 #endif
 
 class RBJv4
