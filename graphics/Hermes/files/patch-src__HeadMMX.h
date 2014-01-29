--- ./src/HeadMMX.h.orig	2000-12-06 05:55:28.000000000 +0100
+++ ./src/HeadMMX.h	2014-01-17 03:59:56.000000000 +0100
@@ -51,7 +51,7 @@
 
 /* Fix the underscore business with ELF compilers */
 
-#if defined(__ELF__) && defined(__GNUC__)
+#if defined(__ELF__) && defined(__GNUC__) && __GNUC__ < 4
   #ifdef __cplusplus 
   extern "C" {   
   #endif
