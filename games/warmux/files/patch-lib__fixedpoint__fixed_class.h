--- ./lib/fixedpoint/fixed_class.h.orig	2010-04-18 21:42:49.000000000 +0400
+++ ./lib/fixedpoint/fixed_class.h	2010-04-24 14:38:36.456848203 +0400
@@ -50,6 +50,12 @@
 #ifdef __APPLE__
   #define SIZE_T_FIXEDPOINT_METHODS
 #endif
+
+#ifdef __FreeBSD__
+  #include <machine/elf.h>
+  #define __WORDSIZE __ELF_WORD_SIZE
+#endif
+
 #if __WORDSIZE == 64
   #define SIZE_T_FIXEDPOINT_METHODS
 #endif
