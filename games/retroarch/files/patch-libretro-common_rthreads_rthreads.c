--- libretro-common/rthreads/rthreads.c.orig	2016-07-16 23:05:18 UTC
+++ libretro-common/rthreads/rthreads.c
@@ -57,6 +57,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
