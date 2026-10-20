--- src/include/sysdeps.h.orig	2026-10-20 01:13:44 UTC
+++ src/include/sysdeps.h
@@ -60,6 +60,9 @@
 #define SAHF_SETO_PROFITABLE
 #elif defined(__powerpc__) || defined(_M_PPC)
 #define CPU_powerpc 1
+#if defined(__powerpc64__)
+#define CPU_64_BIT 1
+#endif
 #elif defined(__riscv) && defined(__riscv_xlen) && __riscv_xlen == 64
 #define CPU_riscv64 1
 #define CPU_64_BIT 1
