--- src/HeadMMX.h.orig	Thu Aug 30 19:26:59 2007
+++ src/HeadMMX.h	Thu Aug 30 19:27:59 2007
@@ -51,7 +51,7 @@
 
 /* Fix the underscore business with ELF compilers */
 
-#if defined(__ELF__) && defined(__GNUC__)
+#if defined(__ELF__) && defined(__GNUC__) && __GNUC__ < 4
   #ifdef __cplusplus 
   extern "C" {   
   #endif
