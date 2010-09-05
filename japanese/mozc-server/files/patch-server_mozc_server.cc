--- server/mozc_server.cc.org	2010-09-05 10:11:21.205396567 +0900
+++ server/mozc_server.cc	2010-09-05 10:36:15.099047296 +0900
@@ -29,6 +29,8 @@
 
 #ifdef OS_WINDOWS
 #include <windows.h>
+#else
+#include <signal.h>
 #endif
 
 #include "base/base.h"
@@ -46,6 +48,23 @@
 mozc::SessionServer *g_session_server = NULL;
 }
 
+#ifndef OS_WINDOWS
+static void sig_func(int num)
+{
+  VLOG(1) << "signal " << num << " recieved.";
+  switch (num) {
+  case SIGINT:
+  case SIGHUP:
+  case SIGTERM:
+    if (g_session_server)
+      g_session_server->Terminate();
+    break;
+  default:
+    break;
+  }
+}
+#endif
+
 namespace mozc {
 namespace {
 
@@ -122,6 +141,12 @@
       return -1;
     }
 
+#ifndef OS_WINDOWS
+    ::signal(SIGINT, sig_func);
+    ::signal(SIGHUP, sig_func);
+    ::signal(SIGTERM, sig_func);
+#endif
+
     // Create a new thread.
     // We can't call Loop() as Loop() doesn't make a thread.
     // We have to make a thread here so that ShutdownSessionCallback()
