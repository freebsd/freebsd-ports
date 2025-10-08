--- 3rdparty/lzma/C/Sha256Opt.c.orig	2025-09-24 14:56:11 UTC
+++ 3rdparty/lzma/C/Sha256Opt.c
@@ -202,7 +202,7 @@ void Z7_FASTCALL Sha256_UpdateBlocks_HW(UInt32 state[8
 
 #endif // USE_HW_SHA
 
-#elif defined(MY_CPU_ARM_OR_ARM64)
+#elif defined(MY_CPU_ARM64)
 
   #if defined(__clang__)
     #if (__clang_major__ >= 8) // fix that check
