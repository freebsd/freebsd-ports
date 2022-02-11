--- ffcall-abi.h.orig	2018-11-18 21:47:39 UTC
+++ ffcall-abi.h
@@ -75,7 +75,7 @@
 #endif
 #endif
 #ifndef __sparc64__
-#if defined(__sparcv9) /* GCC/Solaris, Sun C */ || defined(__arch64__) /* GCC/Linux */
+#if defined(__sparcv9) /* GCC/Solaris, Sun C */
 #define __sparc64__ 1
 #endif
 #endif
