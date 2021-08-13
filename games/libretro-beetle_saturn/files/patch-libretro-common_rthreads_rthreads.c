--- libretro-common/rthreads/rthreads.c.orig	2021-06-22 13:57:12 UTC
+++ libretro-common/rthreads/rthreads.c
@@ -64,6 +64,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
