--- C/CpuArch.h.orig	2024-12-18 16:06:28 UTC
+++ C/CpuArch.h
@@ -247,7 +247,6 @@ MY_CPU_64BIT means that processor can work with 64-bit
     || defined(MY_CPU_ARM_LE) \
     || defined(MY_CPU_ARM64_LE) \
     || defined(MY_CPU_IA64_LE) \
-    || defined(_LITTLE_ENDIAN) \
     || defined(__LITTLE_ENDIAN__) \
     || defined(__ARMEL__) \
     || defined(__THUMBEL__) \
