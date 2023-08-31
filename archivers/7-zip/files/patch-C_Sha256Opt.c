--- C/Sha256Opt.c.orig	2023-08-31 09:13:13 UTC
+++ C/Sha256Opt.c
@@ -202,7 +202,7 @@ void Z7_FASTCALL Sha256_UpdateBlocks_HW(UInt32 state[8
 
 #endif // USE_HW_SHA
 
-#elif defined(MY_CPU_ARM_OR_ARM64)
+#elif defined(MY_CPU_ARM64)
 
   #if defined(__clang__)
     #if (__clang_major__ >= 8) // fix that check
