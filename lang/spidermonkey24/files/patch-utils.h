--- ../../mfbt/double-conversion/utils.h.orig	2016-01-04 09:48:39.700168000 +0000
+++ ../../mfbt/double-conversion/utils.h	2016-01-04 09:49:18.136290000 +0000
@@ -58,7 +58,8 @@
     defined(__mips__) || defined(__powerpc__) || \
     defined(__sparc__) || defined(__sparc) || defined(__s390__) || \
     defined(__SH4__) || defined(__alpha__) || \
-    defined(_MIPS_ARCH_MIPS32R2)
+    defined(_MIPS_ARCH_MIPS32R2) || \
+    defined(__AARCH64EL__)
 #define DOUBLE_CONVERSION_CORRECT_DOUBLE_OPERATIONS 1
 #elif defined(_M_IX86) || defined(__i386__) || defined(__i386)
 #if defined(_WIN32)
