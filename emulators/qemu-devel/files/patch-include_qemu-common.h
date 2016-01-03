--- include/qemu-common.h.orig	2015-11-03 20:01:34 UTC
+++ include/qemu-common.h
@@ -469,7 +469,9 @@ void qemu_hexdump(const char *buf, FILE 
 #define VEC_OR(v1, v2) ((v1) | (v2))
 /* altivec.h may redefine the bool macro as vector type.
  * Reset it to POSIX semantics. */
+#ifndef __cplusplus
 #define bool _Bool
+#endif
 #elif defined __SSE2__
 #include <emmintrin.h>
 #define VECTYPE        __m128i
