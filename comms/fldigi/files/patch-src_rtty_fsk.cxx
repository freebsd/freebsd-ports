--- src/rtty/fsk.cxx.orig	2023-08-04 01:13:40 UTC
+++ src/rtty/fsk.cxx
@@ -50,10 +50,10 @@
 #    include <sys/time.h>
 #  endif
 #endif
-
 #include <math.h>
 #include <stdio.h>
 
+#ifndef __FreeBSD__
 #ifdef __WIN32__
 #  include <windows.h>
 //#  include <chrono>
@@ -67,6 +67,7 @@
 //#    include <chrono>
 #    include <sys/timerfd.h>
 #  endif
+#endif
 #endif
 
 #include "threads.h"
