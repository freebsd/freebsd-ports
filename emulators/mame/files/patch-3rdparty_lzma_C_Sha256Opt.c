--- 3rdparty/lzma/C/Sha256Opt.c.orig	2023-05-30 17:50:57 UTC
+++ 3rdparty/lzma/C/Sha256Opt.c
@@ -212,7 +212,7 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[
 
 #endif // USE_HW_SHA
 
-#elif defined(MY_CPU_ARM_OR_ARM64)
+#elif defined(MY_CPU_ARM64)
 
   #if defined(__clang__)
     #if (__clang_major__ >= 8) // fix that check
