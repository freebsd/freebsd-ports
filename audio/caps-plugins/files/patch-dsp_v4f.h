--- dsp/v4f.h.orig	2016-03-15 10:26:52 UTC
+++ dsp/v4f.h
@@ -71,6 +71,13 @@ inline float v4f_sum (v4f_t v)
 	return f[0]+f[1]+f[2]+f[3];
 }
 
+#ifdef __clang__
+inline float __builtin_cosf2(float v) { return __builtin_cosf(v); }
+inline float __builtin_sinf2(float v) { return __builtin_sinf(v); }
+#define __builtin_cosf __builtin_cosf2
+#define __builtin_sinf __builtin_sinf2
+#endif
+
 /* mapping a float to float function [e.g. sinf() e.a.] to a vector */
 typedef float (*f2f_fn) (float f);
 
