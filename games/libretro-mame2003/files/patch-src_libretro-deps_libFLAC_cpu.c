--- src/libretro-deps/libFLAC/cpu.c.orig	2020-01-12 04:45:51 UTC
+++ src/libretro-deps/libFLAC/cpu.c
@@ -79,6 +79,9 @@ static void sigill_handler (int sig)
 #endif
 
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#ifndef __BSD_VISIBLE
+#define __BSD_VISIBLE 1
+#endif
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
