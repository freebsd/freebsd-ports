--- third_party/boringssl/src/crypto/refcount_c11.c.orig	2022-05-11 07:02:47 UTC
+++ third_party/boringssl/src/crypto/refcount_c11.c
@@ -24,6 +24,9 @@
 
 #include <openssl/type_check.h>
 
+#if !defined(__cplusplus) && !defined(static_assert)
+#define static_assert _Static_assert
+#endif
 
 // See comment above the typedef of CRYPTO_refcount_t about these tests.
 static_assert(alignof(CRYPTO_refcount_t) == alignof(_Atomic CRYPTO_refcount_t),
