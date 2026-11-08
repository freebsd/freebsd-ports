--- swift-crypto/Sources/CCryptoBoringSSL/include/CCryptoBoringSSL_target.h.orig	2026-10-10 18:48:34 UTC
+++ swift-crypto/Sources/CCryptoBoringSSL/include/CCryptoBoringSSL_target.h
@@ -54,6 +54,10 @@
 #define OPENSSL_32_BIT
 #elif defined(__myriad2__)
 #define OPENSSL_32_BIT
+#elif defined(__powerpc64__) || defined(__PPC64__)
+// 64-bit PowerPC.  Assembly support was dropped upstream; the portable C
+// implementation (OPENSSL_NO_ASM) is used on this target.
+#define OPENSSL_64_BIT
 #else
 // The list above enumerates the platforms that BoringSSL supports. For these
 // platforms we keep a reasonable bar of not breaking them: automated test
