--- src/cw_rtty/fsk.cxx.orig	2022-05-04 22:44:19 UTC
+++ src/cw_rtty/fsk.cxx
@@ -39,7 +39,9 @@
 #include <string.h>
 #include <unistd.h>
 
-//#include <time.h>
+#ifdef __FreeBSD__
+#include <time.h>
+#else
 #if !HAVE_CLOCK_GETTIME
 #  ifdef __APPLE__
 #    include <mach/mach_time.h>
@@ -50,10 +52,12 @@
 #    include <sys/time.h>
 #  endif
 #endif
+#endif
 
 #include <math.h>
 #include <stdio.h>
 
+#ifndef __FreeBSD__
 #ifdef __WIN32__
 #  include <windows.h>
 //#  include <chrono>
@@ -67,6 +71,7 @@
 //#    include <chrono>
 #    include <sys/timerfd.h>
 #  endif
+#endif
 #endif
 
 #include "threads.h"
