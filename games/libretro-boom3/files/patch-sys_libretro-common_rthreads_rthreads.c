--- sys/libretro-common/rthreads/rthreads.c.orig	2023-10-28 13:28:00 UTC
+++ sys/libretro-common/rthreads/rthreads.c
@@ -58,7 +58,7 @@
 #include <time.h>
 #endif
 
-#if defined(VITA) || defined(BSD) || defined(ORBIS)
+#if defined(VITA) || defined(BSD) || defined(ORBIS) || (__FreeBSD__ <= 12)
 #include <sys/time.h>
 #endif
 
