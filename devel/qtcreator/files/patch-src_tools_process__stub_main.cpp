--- src/tools/process_stub/main.cpp.orig	2024-11-27 10:00:23 UTC
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
 #elif defined(Q_OS_LINUX)
     if (debugMode) {
         qCInfo(log) << "Waiting for SIGTRAP from inferiors execve ...";
@@ -287,6 +289,11 @@ void setupUnixInferior()
             *shared_child_pid = getpid();
             // Suspend ourselves ...
             raise(SIGSTOP);
+        });
+#elif defined(Q_OS_FREEBSD)
+        // PT_TRACE_ME will stop execution of the child process as soon as execve is called.
+        inferiorProcess.setChildProcessModifier([] {
+            ptrace(PT_TRACE_ME, 0, 0, 0);
         });
 #elif defined(Q_OS_LINUX)
         // PTRACE_TRACEME will stop execution of the child process as soon as execve is called.
