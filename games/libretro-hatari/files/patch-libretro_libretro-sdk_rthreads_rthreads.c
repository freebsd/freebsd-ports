--- libretro/libretro-sdk/rthreads/rthreads.c.orig	2020-03-17 22:37:38 UTC
+++ libretro/libretro-sdk/rthreads/rthreads.c
@@ -44,6 +44,8 @@
 #include <mach/mach.h>
 #endif
 
+#include <time.h>
+
 struct thread_data
 {
    void (*func)(void*);
