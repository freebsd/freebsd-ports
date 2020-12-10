--- src/HeadX86.h.orig	2000-12-06 04:55:28 UTC
+++ src/HeadX86.h
@@ -83,7 +83,7 @@ extern int32 ConvertX86p16_32BGRA888_LUT_X86[512];
 
 /* Now fix up the ELF underscore problem */
 
-#if defined(__ELF__) && defined(__GNUC__)
+#if defined(__ELF__) && defined(__GNUC__) && __GNUC__ < 4
   #ifdef __cplusplus
   extern "C" {
   #endif
