--- base/process/process_handle.cc.orig	2019-12-12 12:38:59 UTC
+++ base/process/process_handle.cc
@@ -28,7 +28,7 @@ UniqueProcId GetUniqueIdForProcess() {
              : UniqueProcId(GetCurrentProcId());
 }
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 
 void InitUniqueIdForProcessInPidNamespace(ProcessId pid_outside_of_namespace) {
   DCHECK(pid_outside_of_namespace != kNullProcessId);
