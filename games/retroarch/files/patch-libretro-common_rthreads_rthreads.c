--- libretro-common/rthreads/rthreads.c.orig	2016-05-02 20:17:12 UTC
+++ libretro-common/rthreads/rthreads.c
@@ -53,6 +53,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <sys/time.h>
+
 struct thread_data
 {
    void (*func)(void*);
