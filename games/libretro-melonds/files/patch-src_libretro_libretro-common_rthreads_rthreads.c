--- src/libretro/libretro-common/rthreads/rthreads.c.orig	2022-07-12 14:45:04 UTC
+++ src/libretro/libretro-common/rthreads/rthreads.c
@@ -67,6 +67,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
