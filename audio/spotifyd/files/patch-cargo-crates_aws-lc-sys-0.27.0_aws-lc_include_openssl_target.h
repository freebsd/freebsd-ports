--- cargo-crates/aws-lc-sys-0.27.0/aws-lc/include/openssl/target.h.orig	2025-09-03 10:05:29 UTC
+++ cargo-crates/aws-lc-sys-0.27.0/aws-lc/include/openssl/target.h
@@ -34,14 +34,14 @@
 #elif defined(__ARMEL__) || defined(_M_ARM)
 #define OPENSSL_32_BIT
 #define OPENSSL_ARM
-#elif (defined(__PPC64__) || defined(__powerpc64__)) && defined(_LITTLE_ENDIAN)
+#elif (defined(__PPC64__) || defined(__powerpc64__)) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
 #define OPENSSL_64_BIT
 #define OPENSSL_PPC64LE
-#elif (defined(__PPC64__) || defined(__powerpc64__)) && defined(_BIG_ENDIAN)
+#elif (defined(__PPC64__) || defined(__powerpc64__)) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
 #define OPENSSL_64_BIT
 #define OPENSSL_PPC64BE
 #define OPENSSL_BIG_ENDIAN
-#elif (defined(__PPC__) || defined(__powerpc__)) && defined(_BIG_ENDIAN)
+#elif (defined(__PPC__) || defined(__powerpc__)) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
 #define OPENSSL_32_BIT
 #define OPENSSL_PPC32BE
 #define OPENSSL_BIG_ENDIAN
