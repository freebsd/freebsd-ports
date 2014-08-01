--- src/lib/lib7z/CpuArch.h.orig
+++ src/lib/lib7z/CpuArch.h
@@ -16,7 +16,7 @@
 If MY_CPU_LE_UNALIGN is not defined, we don't know about these properties of platform.
 */
 
-#if defined(_M_X64) || defined(_M_AMD64) || defined(__x86_64__)
+#if defined(__amd64__) || defined(_M_X64) || defined(_M_AMD64) || defined(__x86_64__)
 #define MY_CPU_AMD64
 #endif
 
