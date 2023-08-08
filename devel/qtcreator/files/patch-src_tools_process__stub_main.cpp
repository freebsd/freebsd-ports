--- src/tools/process_stub/main.cpp.orig	2023-06-08 07:45:07 UTC
+++ src/tools/process_stub/main.cpp
@@ -22,7 +22,7 @@
 #include <unistd.h>
 #endif
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
 #include <sys/ptrace.h>
 #endif
 
@@ -211,6 +211,9 @@ void onInferiorStarted()
     // In debug mode we use the poll timer to send the pid.
     if (!debugMode)
         sendPid(inferiorId);
+#elif defined(Q_OS_FREEBSD)
+    ptrace(PT_DETACH, inferiorId, 0, SIGSTOP);
+    sendPid(inferiorId);
 #else
     ptrace(PTRACE_DETACH, inferiorId, 0, SIGSTOP);
     sendPid(inferiorId);
@@ -230,6 +233,9 @@ void setupUnixInferior()
             // Suspend ourselves ...
             raise(SIGSTOP);
         });
+#elif defined(Q_OS_FREEBSD)
+        // PT_TRACE_ME will stop execution of the child process as soon as execve is called.
+        inferiorProcess.setChildProcessModifier([] { ptrace(PT_TRACE_ME, 0, 0, 0); });
 #else
         // PTRACE_TRACEME will stop execution of the child process as soon as execve is called.
         inferiorProcess.setChildProcessModifier([] { ptrace(PTRACE_TRACEME, 0, 0, 0); });
