--- libretro-common/rthreads/rthreads.c.orig	2023-10-28 20:46:34 UTC
+++ libretro-common/rthreads/rthreads.c
@@ -56,7 +56,7 @@
 #include <time.h>
 #endif
 
-#if defined(VITA) || defined(BSD) || defined(ORBIS) || defined(__mips__) || defined(_3DS)
+#if defined(VITA) || defined(BSD) || defined(ORBIS) || defined(__mips__) || defined(_3DS) || (__FreeBSD__ <= 12)
 #include <sys/time.h>
 #endif
 
