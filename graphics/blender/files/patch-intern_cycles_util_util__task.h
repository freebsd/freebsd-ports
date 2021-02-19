--- intern/cycles/util/util_task.h.orig	2021-01-21 08:01:04 UTC
+++ intern/cycles/util/util_task.h
@@ -61,7 +61,7 @@ class TaskPool {
   void wait_work(Summary *stats = NULL); /* work and wait until all tasks are done */
   void cancel(); /* cancel all tasks and wait until they are no longer executing */

-  bool canceled(); /* for worker threads, test if canceled */
+  static bool canceled(); /* For worker threads, test if current task pool canceled. */

  protected:
   tbb::task_group tbb_group;
