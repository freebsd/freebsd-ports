--- perf/cairo-perf-micro.c.orig	2020-11-26 23:20:59 UTC
+++ perf/cairo-perf-micro.c
@@ -43,6 +43,7 @@
 #endif
 
 #ifdef HAVE_SCHED_H
+#define _WITH_CPU_SET_T
 #include <sched.h>
 #endif
 
