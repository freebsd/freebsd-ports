--- os.hpp.orig	2026-06-27 11:35:31 UTC
+++ os.hpp
@@ -162,10 +162,13 @@
 
 #if defined(__aarch64__) && (defined(__ARM_FEATURE_CRYPTO) || defined(__ARM_FEATURE_CRC32))
 #include <arm_neon.h>
-#ifndef _APPLE
+#if !defined(_APPLE) && !defined(__FreeBSD__)
 #include <sys/auxv.h>
 #include <asm/hwcap.h>
 #endif
+#ifdef __FreeBSD__
+#include <machine/armreg.h>
+#endif
 #ifdef __ARM_FEATURE_CRYPTO
 #define USE_NEON_AES
 #endif
@@ -173,6 +176,10 @@
 #define USE_NEON_CRC32
 #endif
 #endif
+
+#if defined(OPENSSL_AES)
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
 
 #ifdef  S_IFLNK
 #define SAVE_LINKS
