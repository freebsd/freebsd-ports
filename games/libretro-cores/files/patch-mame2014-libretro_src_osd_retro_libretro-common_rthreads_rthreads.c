--- mame2014-libretro/src/osd/retro/libretro-common/rthreads/rthreads.c.orig	2016-09-09 05:23:19 UTC
+++ mame2014-libretro/src/osd/retro/libretro-common/rthreads/rthreads.c
@@ -44,6 +44,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <time.h>
+
 struct thread_data
 {
    void (*func)(void*);
