--- vba-next/libretro-common/rthreads/rthreads.c.orig	2016-11-07 01:24:49 UTC
+++ vba-next/libretro-common/rthreads/rthreads.c
@@ -60,6 +60,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <time.h>
+
 struct thread_data
 {
    void (*func)(void*);
