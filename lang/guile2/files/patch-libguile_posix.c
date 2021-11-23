--- libguile/posix.c.orig	2019-07-01 05:21:54.000000000 -0700
+++ libguile/posix.c	2021-11-23 12:10:16.007364000 -0800
@@ -28,6 +28,7 @@
 #include <uniconv.h>
 
 #ifdef HAVE_SCHED_H
+#define _WITH_CPU_SET_T
 # include <sched.h>
 #endif
 
