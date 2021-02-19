--- source/blender/blenlib/BLI_task.h.orig	2021-01-21 08:02:26 UTC
+++ source/blender/blenlib/BLI_task.h
@@ -104,8 +104,10 @@ void BLI_task_pool_work_and_wait(TaskPool *pool);
 /* cancel all tasks, keep worker threads running */
 void BLI_task_pool_cancel(TaskPool *pool);

-/* for worker threads, test if canceled */
-bool BLI_task_pool_canceled(TaskPool *pool);
+/* for worker threads, test if current task pool canceled. this function may
+ * only be called from worker threads and pool must be the task pool that the
+ * thread is currently executing a task from. */
+bool BLI_task_pool_current_canceled(TaskPool *pool);

 /* optional userdata pointer to pass along to run function */
 void *BLI_task_pool_user_data(TaskPool *pool);
