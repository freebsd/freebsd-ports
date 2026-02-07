--- desmume/src/libretro-common/rthreads/rthreads.c.orig	2023-11-02 10:28:36 UTC
+++ desmume/src/libretro-common/rthreads/rthreads.c
@@ -48,7 +48,7 @@
 #include <time.h>
 #endif
 
-#if defined(VITA)
+#if defined(VITA) || (__FreeBSD__ <= 12)
 #include <sys/time.h>
 #endif
 
