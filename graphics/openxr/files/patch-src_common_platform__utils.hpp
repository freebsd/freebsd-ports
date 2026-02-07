--- src/common/platform_utils.hpp.orig	2024-07-29 12:32:33 UTC
+++ src/common/platform_utils.hpp
@@ -55,6 +55,8 @@
 #define XR_ARCH_ABI "mips"
 #elif defined(__powerpc64__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
 #define XR_ARCH_ABI "ppc64"
+#elif defined(__powerpc__) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
+#define XR_ARCH_ABI "ppc"
 #elif defined(__powerpc__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
 #define XR_ARCH_ABI "ppc64el"
 #elif defined(__s390x__) || defined(__zarch__)
