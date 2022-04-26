--- C/7zCrc.c.orig	2022-04-12 15:58:06 UTC
+++ C/7zCrc.c
@@ -71,7 +71,7 @@ UInt32 MY_FAST_CALL CrcUpdateT1(UInt32 v, const void *
 
 #ifdef MY_CPU_LE
 
-#if defined(MY_CPU_ARM_OR_ARM64)
+#if defined(MY_CPU_ARM64)
 
 // #pragma message("ARM*")
 
