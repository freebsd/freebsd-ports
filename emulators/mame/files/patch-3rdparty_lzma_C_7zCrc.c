--- 3rdparty/lzma/C/7zCrc.c.orig	2023-05-30 17:50:57 UTC
+++ 3rdparty/lzma/C/7zCrc.c
@@ -71,7 +71,7 @@ UInt32 MY_FAST_CALL CrcUpdateT1(UInt32 v, const void *
 
 #ifdef MY_CPU_LE
 
-#if defined(MY_CPU_ARM_OR_ARM64)
+#if defined(MY_CPU_ARM64)
 
 // #pragma message("ARM*")
 
