--- src/sdk/C/CpuArch.h.orig	2026-09-12 09:26:13 UTC
+++ src/sdk/C/CpuArch.h
@@ -253,7 +253,6 @@ MY_CPU_64BIT means that processor can work with 64-bit
     || defined(MY_CPU_ARM_LE) \
     || defined(MY_CPU_ARM64_LE) \
     || defined(MY_CPU_IA64_LE) \
-    || defined(_LITTLE_ENDIAN) \
     || defined(__LITTLE_ENDIAN__) \
     || defined(__ARMEL__) \
     || defined(__THUMBEL__) \
