--- system/profiler_timer.h.orig	2023-01-30 14:47:11 UTC
+++ system/profiler_timer.h
@@ -33,6 +33,7 @@
 #ifndef PROFILER_TIMER_H
 #define PROFILER_TIMER_H
 
+#include <time.h>	// Required on FreeBSD 12.3
 #include "profiler_counter.h"
 
 /*
