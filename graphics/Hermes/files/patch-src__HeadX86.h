--- ./src/HeadX86.h.orig	2000-12-06 05:55:28.000000000 +0100
+++ ./src/HeadX86.h	2014-01-17 03:59:56.000000000 +0100
@@ -83,7 +83,7 @@
 
 /* Now fix up the ELF underscore problem */
 
-#if defined(__ELF__) && defined(__GNUC__)
+#if defined(__ELF__) && defined(__GNUC__) && __GNUC__ < 4
   #ifdef __cplusplus
   extern "C" {
   #endif
