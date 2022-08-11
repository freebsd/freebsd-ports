--- base/process/process_iterator_openbsd.cc.orig	2022-05-25 04:00:43 UTC
+++ base/process/process_iterator_openbsd.cc
@@ -6,6 +6,9 @@
 
 #include <errno.h>
 #include <stddef.h>
+#include <unistd.h>
+#include <sys/param.h>
+#include <sys/proc.h>
 #include <sys/sysctl.h>
 
 #include "base/logging.h"
@@ -18,12 +21,13 @@ ProcessIterator::ProcessIterator(const ProcessFilter* 
     : index_of_kinfo_proc_(),
       filter_(filter) {
 
-  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_UID, getuid(),
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_UID, static_cast<int>(getuid()),
                 sizeof(struct kinfo_proc), 0 };
 
   bool done = false;
   int try_num = 1;
   const int max_tries = 10;
+  size_t num_of_kinfo_proc;
 
   do {
     size_t len = 0;
@@ -32,7 +36,7 @@ ProcessIterator::ProcessIterator(const ProcessFilter* 
       kinfo_procs_.resize(0);
       done = true;
     } else {
-      size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
+      num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
       // Leave some spare room for process table growth (more could show up
       // between when we check and now)
       num_of_kinfo_proc += 16;
@@ -48,7 +52,7 @@ ProcessIterator::ProcessIterator(const ProcessFilter* 
         }
       } else {
         // Got the list, just make sure we're sized exactly right
-        size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
+        num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
         kinfo_procs_.resize(num_of_kinfo_proc);
         done = true;
       }
