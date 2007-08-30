--- src/HeadX86.h.orig	Thu Aug 30 19:28:22 2007
+++ src/HeadX86.h	Thu Aug 30 19:28:44 2007
@@ -83,7 +83,7 @@
 
 /* Now fix up the ELF underscore problem */
 
-#if defined(__ELF__) && defined(__GNUC__)
+#if defined(__ELF__) && defined(__GNUC__) && __GNUC__ < 4
   #ifdef __cplusplus
   extern "C" {
   #endif
