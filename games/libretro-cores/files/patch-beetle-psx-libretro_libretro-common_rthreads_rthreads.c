--- beetle-psx-libretro/libretro-common/rthreads/rthreads.c.orig	2016-11-07 01:42:50 UTC
+++ beetle-psx-libretro/libretro-common/rthreads/rthreads.c
@@ -60,6 +60,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
