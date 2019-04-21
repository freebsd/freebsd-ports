--- SharedMemory.cpp.orig	2019-04-21 19:57:39 UTC
+++ SharedMemory.cpp
@@ -11,7 +11,7 @@
 #include <semaphore.h>
 #include <errno.h>
 
-#ifdef COMPILE_FOR_MAC
+#if defined(COMPILE_FOR_MAC) || defined(__FreeBSD__)
   //some Mac's idiosyncrasies: standard SHM libraries are very old and missing some definitions
   #define SHM_NORESERVE 0
 #endif
