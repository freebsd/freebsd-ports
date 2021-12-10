--- CPP/Windows/SystemInfo.cpp.orig	2021-12-10 11:30:40 UTC
+++ CPP/Windows/SystemInfo.cpp
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
 
