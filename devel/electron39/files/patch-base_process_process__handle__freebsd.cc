--- base/process/process_handle_freebsd.cc.orig	2025-03-24 20:50:14 UTC
+++ base/process/process_handle_freebsd.cc
@@ -3,6 +3,7 @@
 // found in the LICENSE file.
 
 #include "base/process/process_handle.h"
+#include "base/files/file_util.h"
 
 #include <limits.h>
 #include <stddef.h>
@@ -20,10 +21,13 @@ ProcessId GetParentProcessId(ProcessHandle process) {
 
 ProcessId GetParentProcessId(ProcessHandle process) {
   struct kinfo_proc info;
-  size_t length;
+  size_t length = sizeof(struct kinfo_proc);
   int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_PID, process};
 
   if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
+    return -1;
+
+  if (length < sizeof(struct kinfo_proc))
     return -1;
   }
 
