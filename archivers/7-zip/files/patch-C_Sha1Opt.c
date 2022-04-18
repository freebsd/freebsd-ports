--- C/Sha1Opt.c.orig	2022-04-12 16:00:26 UTC
+++ C/Sha1Opt.c
@@ -212,7 +212,7 @@ void MY_FAST_CALL Sha1_UpdateBlocks_HW(UInt32 state[5]
 
 #endif // USE_HW_SHA
 
-#elif defined(MY_CPU_ARM_OR_ARM64)
+#elif defined(MY_CPU_ARM64)
 
   #if defined(__clang__)
     #if (__clang_major__ >= 8) // fix that check
