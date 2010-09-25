--- server/mozc_server.cc.org	2010-09-25 12:45:06.069338637 +0900
+++ server/mozc_server.cc	2010-09-25 12:46:24.810331975 +0900
@@ -30,6 +30,9 @@
 #ifdef OS_WINDOWS
 #include <windows.h>
 #endif
+#ifdef __FreeBSD__
+#include <signal.h>
+#endif
 
 #include "base/base.h"
 #include "base/process.h"
@@ -46,6 +49,23 @@
 mozc::SessionServer *g_session_server = NULL;
 }
 
+#ifdef __FreeBSD__
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
 
@@ -122,6 +142,12 @@
       return -1;
     }
 
+#ifdef __FreeBSD__
+    ::signal(SIGINT, sig_func);
+    ::signal(SIGHUP, sig_func);
+    ::signal(SIGTERM, sig_func);
+#endif
+
     // Create a new thread.
     // We can't call Loop() as Loop() doesn't make a thread.
     // We have to make a thread here so that ShutdownSessionCallback()
