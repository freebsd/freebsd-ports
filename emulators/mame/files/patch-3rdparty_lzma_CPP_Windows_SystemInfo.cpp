--- 3rdparty/lzma/CPP/Windows/SystemInfo.cpp.orig	2023-05-30 17:50:57 UTC
+++ 3rdparty/lzma/CPP/Windows/SystemInfo.cpp
@@ -20,6 +20,15 @@
 
 #include <sys/auxv.h>
 
+#if defined(__FreeBSD__)
+unsigned long getauxval(unsigned long type)
+{
+    unsigned long aux = 0;
+    elf_aux_info(type, &aux, sizeof(aux));
+    return aux;
+}
+#endif
+
 // #undef AT_HWCAP    // to debug
 // #undef AT_HWCAP2   // to debug
 
@@ -36,7 +45,7 @@
 #endif
 */
 
-#ifdef MY_CPU_ARM_OR_ARM64
+#if defined(MY_CPU_ARM_OR_ARM64) && !defined(__FreeBSD__)
 #include <asm/hwcap.h>
 #endif
 #endif
