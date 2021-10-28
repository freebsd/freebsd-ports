--- platform.h.orig	2021-10-28 09:13:02 UTC
+++ platform.h
@@ -212,13 +212,6 @@
 #endif
 
 #if !defined (OS_DETECTED)
-#if defined (TARGET_CPU_ARM)
-#define OS_DETECTED
-#define TARGET_OS_NDSFIRMWARE
-#endif
-#endif
-
-#if !defined (OS_DETECTED)
 #if defined (MSDOS) || defined (__DOS__) || defined (__DJGPP__)
 #define OS_DETECTED
 #define TARGET_OS_DOS
