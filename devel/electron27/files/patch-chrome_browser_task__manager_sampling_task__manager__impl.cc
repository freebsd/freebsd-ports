--- chrome/browser/task_manager/sampling/task_manager_impl.cc.orig	2023-05-25 00:41:44 UTC
+++ chrome/browser/task_manager/sampling/task_manager_impl.cc
@@ -217,7 +217,7 @@ void TaskManagerImpl::GetUSERHandles(TaskId task_id,
 }
 
 int TaskManagerImpl::GetOpenFdCount(TaskId task_id) const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return GetTaskGroupByTaskId(task_id)->open_fd_count();
 #else
   return -1;
