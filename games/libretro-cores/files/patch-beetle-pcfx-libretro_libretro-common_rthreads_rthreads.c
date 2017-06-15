--- beetle-pcfx-libretro/libretro-common/rthreads/rthreads.c.orig	2016-09-07 04:41:47 UTC
+++ beetle-pcfx-libretro/libretro-common/rthreads/rthreads.c
@@ -53,6 +53,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
