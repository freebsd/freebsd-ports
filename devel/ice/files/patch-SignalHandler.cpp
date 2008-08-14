--- cpp/src/Slice/SignalHandler.cpp.orig	2008-05-22 18:55:20.000000000 +0200
+++ cpp/src/Slice/SignalHandler.cpp	2008-05-22 18:55:38.000000000 +0200
@@ -52,9 +52,9 @@
 #ifdef _WIN32
     SetConsoleCtrlHandler(signalHandler, TRUE);
 #else
-    sigset(SIGHUP, signalHandler);
-    sigset(SIGINT, signalHandler);
-    sigset(SIGQUIT, signalHandler);
+    signal(SIGHUP, signalHandler);
+    signal(SIGINT, signalHandler);
+    signal(SIGQUIT, signalHandler);
 #endif
 }
 
@@ -63,9 +63,9 @@
 #ifdef _WIN32
     SetConsoleCtrlHandler(signalHandler, FALSE);
 #else
-    sigset(SIGHUP, SIG_DFL);
-    sigset(SIGINT, SIG_DFL);
-    sigset(SIGQUIT, SIG_DFL);
+    signal(SIGHUP, SIG_DFL);
+    signal(SIGINT, SIG_DFL);
+    signal(SIGQUIT, SIG_DFL);
 #endif
 
     _fileList.clear();
