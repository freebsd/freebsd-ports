--- base/process/process_handle_freebsd.cc.orig	2021-09-14 01:51:47 UTC
+++ base/process/process_handle_freebsd.cc
@@ -12,15 +12,19 @@
 #include <unistd.h>
 
 #include "base/cxx17_backports.h"
+#include "base/files/file_path.h"
 
 namespace base {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
+  size_t length = sizeof(struct kinfo_proc);
   int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process };
 
   if (sysctl(mib, base::size(mib), &info, &length, NULL, 0) < 0)
+    return -1;
+
+  if (length < sizeof(struct kinfo_proc))
     return -1;
 
   return info.ki_ppid;
