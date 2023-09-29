--- src/tools/process_stub/main.cpp.orig	2023-09-27 07:28:08 UTC
+++ src/tools/process_stub/main.cpp
@@ -22,10 +22,9 @@
 #include <unistd.h>
 #endif
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 #include <sys/ptrace.h>
 #include <sys/wait.h>
-#include <sys/prctl.h>
 #endif
 
 #include <iostream>
@@ -254,6 +253,9 @@ void onInferiorStarted()
     // In debug mode we use the poll timer to send the pid.
     if (!debugMode)
         sendPid(inferiorId);
+#elif defined(Q_OS_FREEBSD)
+    ptrace(PT_DETACH, inferiorId, 0, SIGSTOP);
+    sendPid(inferiorId);
 #else
 
     if (debugMode) {
@@ -287,6 +289,9 @@ void setupUnixInferior()
             // Suspend ourselves ...
             raise(SIGSTOP);
         });
+#elif defined(Q_OS_FREEBSD)
+        // PT_TRACE_ME will stop execution of the child process as soon as execve is called.
+        inferiorProcess.setChildProcessModifier([] { ptrace(PT_TRACE_ME, 0, 0, 0); });
 #else
         // PTRACE_TRACEME will stop execution of the child process as soon as execve is called.
         inferiorProcess.setChildProcessModifier([] {
