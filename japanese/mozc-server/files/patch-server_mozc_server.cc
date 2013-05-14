--- server/mozc_server.cc.orig	2013-03-29 13:33:26.000000000 +0900
+++ server/mozc_server.cc	2013-04-27 15:18:29.000000000 +0900
@@ -32,6 +32,9 @@
 #ifdef OS_WIN
 #include <windows.h>
 #endif
+#ifdef OS_FREEBSD
+#include <signal.h>
+#endif
 
 #include <cstddef>
 #include <string>
@@ -51,6 +54,23 @@
 mozc::SessionServer *g_session_server = NULL;
 }
 
+#ifdef OS_FREEBSD
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
 
@@ -132,6 +152,12 @@
       return -1;
     }
 
+#ifdef OS_FREEBSD
+    ::signal(SIGINT, sig_func);
+    ::signal(SIGHUP, sig_func);
+    ::signal(SIGTERM, sig_func);
+#endif
+
 #if defined(OS_WIN)
     // On Windows, ShutdownSessionCallback is not called intentionally in order
     // to avoid crashes oritinates from it. See b/2696087.
