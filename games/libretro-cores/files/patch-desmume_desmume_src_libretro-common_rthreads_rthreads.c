--- desmume/desmume/src/libretro-common/rthreads/rthreads.c.orig	2016-11-01 17:09:43 UTC
+++ desmume/desmume/src/libretro-common/rthreads/rthreads.c
@@ -60,6 +60,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
