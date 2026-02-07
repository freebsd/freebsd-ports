--- libretro-common/rthreads/rthreads.c.orig	2023-11-02 10:57:19 UTC
+++ libretro-common/rthreads/rthreads.c
@@ -55,7 +55,7 @@
 #include <time.h>
 #endif
 
-#if defined(VITA) || defined(BSD) || defined(ORBIS)
+#if defined(VITA) || defined(BSD) || defined(ORBIS) || (__FreeBSD__ <= 12)
 #include <sys/time.h>
 #elif defined(__PS3__)
 #include <sys/sys_time.h>
