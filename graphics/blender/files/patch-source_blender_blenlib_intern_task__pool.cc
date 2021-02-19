--- source/blender/blenlib/intern/task_pool.cc.orig	2020-11-25 19:01:32 UTC
+++ source/blender/blenlib/intern/task_pool.cc
@@ -131,6 +131,12 @@ class TBBTaskGroup : public tbb::task_group {
  public:
   TBBTaskGroup(TaskPriority priority)
   {
+#  if TBB_INTERFACE_VERSION_MAJOR >= 12
+    /* TODO: support priorities in TBB 2021, where they are only available as
+     * part of task arenas, no longer for task groups. Or remove support for
+     * task priorities if they are no longer useful. */
+    UNUSED_VARS(priority);
+#  else
     switch (priority) {
       case TASK_PRIORITY_LOW:
         my_context.set_priority(tbb::priority_low);
@@ -139,6 +145,7 @@ class TBBTaskGroup : public tbb::task_group {
         my_context.set_priority(tbb::priority_normal);
         break;
     }
+#endif
   }

   ~TBBTaskGroup()
@@ -268,7 +275,7 @@ static bool tbb_task_pool_canceled(TaskPool *pool)
 {
 #ifdef WITH_TBB
   if (pool->use_threads) {
-    return pool->tbb_group.is_canceling();
+    return tbb::is_current_task_group_canceling();
   }
 #else
   UNUSED_VARS(pool);
@@ -520,7 +527,7 @@ void BLI_task_pool_cancel(TaskPool *pool)
   }
 }

-bool BLI_task_pool_canceled(TaskPool *pool)
+bool BLI_task_pool_current_canceled(TaskPool *pool)
 {
   switch (pool->type) {
     case TASK_POOL_TBB:
