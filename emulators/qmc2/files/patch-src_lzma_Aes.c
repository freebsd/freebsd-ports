--- src/lzma/Aes.c.orig	2022-04-29 08:33:05 UTC
+++ src/lzma/Aes.c
@@ -55,7 +55,7 @@ static Byte InvS[256];
 
 #ifdef MY_CPU_X86_OR_AMD64
   #define USE_HW_AES
-#elif defined(MY_CPU_ARM_OR_ARM64) && defined(MY_CPU_LE)
+#elif defined(MY_CPU_ARM) && defined(MY_CPU_LE)
   #if defined(__clang__)
     #if (__clang_major__ >= 8) // fix that check
       #define USE_HW_AES
