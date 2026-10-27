--- include/dosbox.h.orig	2026-10-27 11:58:28 UTC
+++ include/dosbox.h
@@ -104,6 +104,9 @@
 #elif defined(__arm__) || defined(__aarch64__)
 // ARMv7 (Raspberry Pi) does not have long double, sizeof(long double) == sizeof(double)
 // ARM 64 has a quadruple-precision float instead of the 80-bit extended precision one used by x87
+#elif defined(__LDBL_MANT_DIG__) && __LDBL_MANT_DIG__ != 64
+// long double is not the x87 80-bit extended format: either the same as double (FreeBSD/powerpc64
+// and powerpc64le before 16.0) or IEEE binary128 (Linux ppc64le, riscv64, s390x, loongarch64)
 #else
 // GCC, other compilers, have sizeof(long double) == 10 80-bit IEEE
 #define HAS_LONG_DOUBLE		1
