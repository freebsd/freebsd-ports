vec_sld concatenates its operands in big-endian element order. On
little-endian PowerPC swap the operands and the shift count so the
Altivec code keeps the element order it was written for (same fix as
biology/hmmer).

--- easel/esl_vmx.h.orig	2023-09-06 14:14:14 UTC
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
