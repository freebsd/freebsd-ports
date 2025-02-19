--- os.hpp.orig	2025-02-12 14:05:27 UTC
+++ os.hpp
@@ -158,10 +158,13 @@
 
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
@@ -169,6 +172,10 @@
 #define USE_NEON_CRC32
 #endif
 #endif
+
+#if defined(OPENSSL_AES)
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
 
 #ifdef  S_IFLNK
 #define SAVE_LINKS
