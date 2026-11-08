--- easel/esl_vmx.h.orig	2026-10-13 07:42:00 UTC
+++ easel/esl_vmx.h
@@ -11,6 +11,10 @@
 #include <stdio.h>
 #include <altivec.h>
 
+#ifdef __LITTLE_ENDIAN__
+#define vec_sld(a, b, c) vec_sld((b), (a), 16 - (c))
+#endif
+
 
 extern vector float esl_vmx_logf(vector float x);
 extern vector float esl_vmx_expf(vector float x);
