--- src/libretro/libretro-common/rthreads/rthreads.c.orig	2023-11-02 10:45:06 UTC
+++ src/libretro/libretro-common/rthreads/rthreads.c
@@ -58,7 +58,7 @@
 #include <time.h>
 #endif
 
-#if defined(VITA) || defined(BSD) || defined(ORBIS)
+#if defined(VITA) || defined(BSD) || defined(ORBIS) || (__FreeBSD__ <= 12)
 #include <sys/time.h>
 #endif
 
