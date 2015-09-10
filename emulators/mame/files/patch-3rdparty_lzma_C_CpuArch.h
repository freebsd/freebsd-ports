--- 3rdparty/lzma/C/CpuArch.h.orig	2015-05-24 15:52:12 UTC
+++ 3rdparty/lzma/C/CpuArch.h
@@ -16,7 +16,7 @@ MY_CPU_LE_UNALIGN means that CPU is LITT
 If MY_CPU_LE_UNALIGN is not defined, we don't know about these properties of platform.
 */
 
-#if defined(_M_X64) || defined(_M_AMD64) || defined(__x86_64__)
+#if defined(_M_X64) || defined(_M_AMD64) || defined(__x86_64__) || defined(__amd64__)
 #define MY_CPU_AMD64
 #endif
 
