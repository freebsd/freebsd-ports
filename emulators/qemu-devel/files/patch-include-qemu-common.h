--- a/include/qemu-common.h
+++ b/include/qemu-common.h
@@ -445,7 +445,9 @@ void qemu_hexdump(const char *buf, FILE 
 #define ALL_EQ(v1, v2) vec_all_eq(v1, v2)
 /* altivec.h may redefine the bool macro as vector type.
  * Reset it to POSIX semantics. */
+#ifndef __cplusplus
 #define bool _Bool
+#endif
 #elif defined __SSE2__
 #include <emmintrin.h>
 #define VECTYPE        __m128i
