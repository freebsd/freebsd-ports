--- intern/cycles/util/util_task.cpp.orig	2021-01-21 08:00:29 UTC
+++ intern/cycles/util/util_task.cpp
@@ -62,7 +62,7 @@ void TaskPool::cancel()

 bool TaskPool::canceled()
 {
-  return tbb_group.is_canceling();
+  return tbb::is_current_task_group_canceling();
 }

 /* Task Scheduler */
