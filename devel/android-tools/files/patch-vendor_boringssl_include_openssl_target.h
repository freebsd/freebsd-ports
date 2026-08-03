--- vendor/boringssl/include/openssl/target.h.orig	2026-08-03 09:03:49 UTC
+++ vendor/boringssl/include/openssl/target.h
@@ -54,6 +54,11 @@
 #define OPENSSL_32_BIT
 #elif defined(__myriad2__)
 #define OPENSSL_32_BIT
+#elif defined(__powerpc64__)
+// PowerPC64 has no BoringSSL assembly; the portable C code is used and the
+// build must define OPENSSL_NO_ASM.  BoringSSL only officially supports
+// little-endian, so big-endian ppc64 is unverified.
+#define OPENSSL_64_BIT
 #else
 // The list above enumerates the platforms that BoringSSL supports. For these
 // platforms we keep a reasonable bar of not breaking them: automated test
