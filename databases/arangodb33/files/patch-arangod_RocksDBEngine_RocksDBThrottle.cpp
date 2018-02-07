--- arangod/RocksDBEngine/RocksDBThrottle.cpp.orig	2018-01-05 13:56:52 UTC
+++ arangod/RocksDBEngine/RocksDBThrottle.cpp
@@ -515,8 +515,8 @@ void RocksDBThrottle::AdjustThreadPriori
     pid_t tid;
     int ret_val;
 
-    tid = syscall(SYS_gettid);
-    if (-1!=(int)tid)
+    ret_val = syscall(SYS_thr_self, &tid);
+    if (-1!=ret_val)
     {
       errno=0;
       ret_val=getpriority(PRIO_PROCESS, tid);
@@ -534,8 +534,9 @@ void RocksDBThrottle::AdjustThreadPriori
       && (gThreadPriority._basePriority+Adjustment)!=gThreadPriority._currentPriority) {
 
     pid_t tid;
-    tid = syscall(SYS_gettid);
-    if (-1!=(int)tid)
+    int ret_val;
+    ret_val = syscall(SYS_thr_self, &tid);
+    if (-1!=(int)ret_val)
     {
       gThreadPriority._currentPriority = gThreadPriority._basePriority + Adjustment;
       setpriority(PRIO_PROCESS, tid, gThreadPriority._currentPriority);
