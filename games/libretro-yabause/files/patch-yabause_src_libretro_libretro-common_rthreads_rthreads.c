--- yabause/src/libretro/libretro-common/rthreads/rthreads.c.orig	2023-11-02 18:30:58 UTC
+++ yabause/src/libretro/libretro-common/rthreads/rthreads.c
@@ -55,7 +55,7 @@
 #include <time.h>
 #endif
 
-#if defined(VITA) || defined(BSD) || defined(ORBIS)
+#if defined(VITA) || defined(BSD) || defined(ORBIS) || (__FreeBSD__ <= 12)
 #include <sys/time.h>
 #endif
 
