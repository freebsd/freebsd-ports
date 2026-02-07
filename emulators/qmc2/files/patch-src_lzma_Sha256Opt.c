--- src/lzma/Sha256Opt.c.orig	2022-04-29 08:33:05 UTC
+++ src/lzma/Sha256Opt.c
@@ -212,7 +212,7 @@ void MY_FAST_CALL Sha256_UpdateBlocks_HW(UInt32 state[
 
 #endif // USE_HW_SHA
 
-#elif defined(MY_CPU_ARM_OR_ARM64)
+#elif defined(MY_CPU_ARM64)
 
   #if defined(__clang__)
     #if (__clang_major__ >= 8) // fix that check
