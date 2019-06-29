--- Ghidra/Features/Decompiler/src/decompile/cpp/types.h.orig	2019-04-03 17:38:23 UTC
+++ Ghidra/Features/Decompiler/src/decompile/cpp/types.h
@@ -101,6 +101,36 @@ typedef char int1;
 typedef uint8 uintp;
 #endif
 
+#if defined (__FreeBSD__) && defined (__i386__)
+#define HOST_ENDIAN 0
+typedef unsigned long uintm;
+typedef long intm;
+typedef unsigned long long uint8;
+typedef long long int8;
+typedef unsigned int uint4;
+typedef int int4;
+typedef unsigned short uint2;
+typedef short int2;
+typedef unsigned char uint1;
+typedef char int1;
+typedef uint4 uintp;
+#endif
+
+#if defined (__FreeBSD__) && defined (__x86_64__)
+#define HOST_ENDIAN 0
+typedef unsigned int uintm;
+typedef int intm;
+typedef unsigned long uint8;
+typedef long int8;
+typedef unsigned int uint4;
+typedef int int4;
+typedef unsigned short uint2;
+typedef short int2;
+typedef unsigned char uint1;
+typedef char int1;
+typedef uint8 uintp;
+#endif
+
 #if defined(_WINDOWS)
 
 #if defined(_WIN64)
