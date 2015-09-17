--- utests/builtin_exp.cpp.orig	2015-01-16 10:24:13 UTC
+++ utests/builtin_exp.cpp
@@ -25,7 +25,11 @@ static void cpu_compiler_math(float *dst
 
   dst[0] = exp(x);
   dst[1] = exp2(x);
+#ifndef __FreeBSD__
   dst[2] = exp10(x);
+#else
+  dst[2] = powf(10,x);
+#endif
   dst[3] = expm1(x);
   dst[4] = x;
 }
