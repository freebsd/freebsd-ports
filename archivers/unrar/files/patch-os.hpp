--- os.hpp.orig	2026-06-27 11:35:31 UTC
+++ os.hpp
@@ -164,8 +164,10 @@
 #include <arm_neon.h>
 #ifndef _APPLE
 #include <sys/auxv.h>
+#ifdef __linux__
 #include <asm/hwcap.h>
 #endif
+#endif
 #ifdef __ARM_FEATURE_CRYPTO
 #define USE_NEON_AES
 #endif
@@ -173,6 +175,10 @@
 #define USE_NEON_CRC32
 #endif
 #endif
+
+#if defined(OPENSSL_AES)
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
 
 #ifdef  S_IFLNK
 #define SAVE_LINKS
