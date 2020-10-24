--- qemu/include/qemu-common.h.orig	2020-10-24 17:16:21 UTC
+++ qemu/include/qemu-common.h
@@ -205,7 +205,6 @@ static inline uint64_t muldiv64(uint64_t a, uint32_t b
 
 /* vector definitions */
 #ifdef __ALTIVEC__
-#include <altivec.h>
 /* The altivec.h header says we're allowed to undef these for
  * C++ compatibility.  Here we don't care about C++, but we
  * undef them anyway to avoid namespace pollution.
@@ -213,6 +212,7 @@ static inline uint64_t muldiv64(uint64_t a, uint32_t b
 #undef vector
 #undef pixel
 #undef bool
+#include <altivec.h>
 #define VECTYPE        __vector unsigned char
 #define SPLAT(p)       vec_splat(vec_ld(0, p), 0)
 #define ALL_EQ(v1, v2) vec_all_eq(v1, v2)
