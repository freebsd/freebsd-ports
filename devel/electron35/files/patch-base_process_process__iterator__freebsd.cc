--- base/process/process_iterator_freebsd.cc.orig	2025-03-24 20:50:14 UTC
+++ base/process/process_iterator_freebsd.cc
@@ -18,7 +18,7 @@ ProcessIterator::ProcessIterator(const ProcessFilter* 
 
 ProcessIterator::ProcessIterator(const ProcessFilter* filter)
     : filter_(filter) {
-  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_UID, getuid()};
+  int mib[] = {CTL_KERN, KERN_PROC, KERN_PROC_UID, (int) getuid()};
 
   bool done = false;
   int try_num = 1;
@@ -37,7 +37,7 @@ ProcessIterator::ProcessIterator(const ProcessFilter* 
       num_of_kinfo_proc += 16;
       kinfo_procs_.resize(num_of_kinfo_proc);
       len = num_of_kinfo_proc * sizeof(struct kinfo_proc);
-      if (sysctl(mib, std::size(mib), &kinfo_procs_[0], &len, NULL, 0) < 0) {
+      if (sysctl(mib, std::size(mib), kinfo_procs_.data(), &len, NULL, 0) < 0) {
         // If we get a mem error, it just means we need a bigger buffer, so
         // loop around again.  Anything else is a real error and give up.
         if (errno != ENOMEM) {
@@ -47,7 +47,7 @@ ProcessIterator::ProcessIterator(const ProcessFilter* 
         }
       } else {
         // Got the list, just make sure we're sized exactly right
-        size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
+        num_of_kinfo_proc = len / sizeof(struct kinfo_proc);
         kinfo_procs_.resize(num_of_kinfo_proc);
         done = true;
       }
@@ -68,19 +68,14 @@ bool ProcessIterator::CheckForNextProcess() {
   for (; index_of_kinfo_proc_ < kinfo_procs_.size(); ++index_of_kinfo_proc_) {
     size_t length;
     struct kinfo_proc kinfo = kinfo_procs_[index_of_kinfo_proc_];
-    int mib[] = {CTL_KERN, KERN_PROC_ARGS, kinfo.ki_pid};
+    int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_ARGS, kinfo.ki_pid };
 
     if ((kinfo.ki_pid > 0) && (kinfo.ki_stat == SZOMB)) {
       continue;
     }
 
-    length = 0;
-    if (sysctl(mib, std::size(mib), NULL, &length, NULL, 0) < 0) {
-      LOG(ERROR) << "failed to figure out the buffer size for a command line";
-      continue;
-    }
-
-    data.resize(length);
+    data.resize(ARG_MAX);
+    length = ARG_MAX;
 
     if (sysctl(mib, std::size(mib), &data[0], &length, NULL, 0) < 0) {
       LOG(ERROR) << "failed to fetch a commandline";
