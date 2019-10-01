--- intern/numaapi/source/build_config.h.orig	2019-09-27 08:55:36 UTC
+++ intern/numaapi/source/build_config.h
@@ -307,6 +307,11 @@
 #    define ARCH_CPU_32_BITS 1
 #    define ARCH_CPU_BIG_ENDIAN 1
 #  endif
+#elif defined(__powerpc64__)
+#  define ARCH_CPU_PPC_FAMILY 1
+#  define ARCH_CPU_PPC 1
+#  define ARCH_CPU_64_BITS 1
+#  define ARCH_CPU_BIG_ENDIAN 1
 #else
 #  error Please add support for your architecture in build_config.h
 #endif
