--- base/message_loop/message_pump_glib.cc.orig	2021-09-14 01:51:47 UTC
+++ base/message_loop/message_pump_glib.cc
@@ -8,6 +8,11 @@
 #include <glib.h>
 #include <math.h>
 
+#if defined(OS_BSD)
+#include <pthread.h>
+#include <pthread_np.h>
+#endif
+
 #include "base/logging.h"
 #include "base/notreached.h"
 #include "base/numerics/safe_conversions.h"
@@ -49,9 +54,13 @@ int GetTimeIntervalMilliseconds(TimeTicks next_task_ti
 }
 
 bool RunningOnMainThread() {
+#if defined(OS_BSD)
+  return pthread_main_np();
+#else
   auto pid = getpid();
   auto tid = PlatformThread::CurrentId();
   return pid > 0 && tid > 0 && pid == tid;
+#endif
 }
 
 // A brief refresher on GLib:
