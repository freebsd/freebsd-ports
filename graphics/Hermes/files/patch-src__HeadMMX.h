--- src/HeadMMX.h.orig	2000-12-06 04:55:28 UTC
+++ src/HeadMMX.h
@@ -51,7 +51,7 @@ void ConvertMMXp32_16RGB555();
 
 /* Fix the underscore business with ELF compilers */
 
-#if defined(__ELF__) && defined(__GNUC__)
+#if defined(__ELF__) && defined(__GNUC__) && __GNUC__ < 4
   #ifdef __cplusplus 
   extern "C" {   
   #endif
