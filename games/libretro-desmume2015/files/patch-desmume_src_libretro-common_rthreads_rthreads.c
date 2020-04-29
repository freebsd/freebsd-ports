--- desmume/src/libretro-common/rthreads/rthreads.c.orig	2020-03-17 22:13:05 UTC
+++ desmume/src/libretro-common/rthreads/rthreads.c
@@ -60,6 +60,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
