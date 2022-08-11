--- yabause/src/libretro/libretro-common/rthreads/rthreads.c.orig	2020-05-02 13:49:27 UTC
+++ yabause/src/libretro/libretro-common/rthreads/rthreads.c
@@ -67,6 +67,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
