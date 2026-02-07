--- OOps/pffft.c.orig	2019-07-12 21:54:19 UTC
+++ OOps/pffft.c
@@ -63,6 +63,9 @@
 #include <stdio.h>
 #include <assert.h>
 #include <stdint.h>
+#if !defined(PFFFT_SIMD_DISABLE) && (defined(__ppc__) || defined(__ppc64__))
+#include <altivec.h>
+#endif
 
 /* detect compiler flavour */
 #if defined(_MSC_VER)
