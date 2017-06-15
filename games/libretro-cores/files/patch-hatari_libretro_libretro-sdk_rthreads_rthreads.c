--- hatari/libretro/libretro-sdk/rthreads/rthreads.c.orig	2016-09-09 05:25:46 UTC
+++ hatari/libretro/libretro-sdk/rthreads/rthreads.c
@@ -44,6 +44,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <time.h>
+
 struct thread_data
 {
    void (*func)(void*);
