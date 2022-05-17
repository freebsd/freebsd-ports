--- core/libretro-common/rthreads/rthreads.c.orig	2021-05-17 21:23:19 UTC
+++ core/libretro-common/rthreads/rthreads.c
@@ -55,10 +55,9 @@
 #include <sys/sys_time.h>
 #else
 #include <pthread.h>
-#include <time.h>
 #endif
 
-#if defined(VITA) || defined(BSD) || defined(ORBIS)
+#if defined(VITA) || defined(__FreeBSD__) || defined(ORBIS)
 #include <sys/time.h>
 #endif
 
