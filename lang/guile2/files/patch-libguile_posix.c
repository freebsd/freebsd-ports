--- libguile/posix.c.orig	2019-07-01 12:21:54 UTC
+++ libguile/posix.c
@@ -28,6 +28,7 @@
 #include <uniconv.h>
 
 #ifdef HAVE_SCHED_H
+#define _WITH_CPU_SET_T
 # include <sched.h>
 #endif
 
