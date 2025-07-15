--- chrome/browser/task_manager/sampling/task_manager_impl.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/task_manager/sampling/task_manager_impl.cc
@@ -234,7 +234,7 @@ int TaskManagerImpl::GetOpenFdCount(TaskId task_id) co
 }
 
 int TaskManagerImpl::GetOpenFdCount(TaskId task_id) const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return GetTaskGroupByTaskId(task_id)->open_fd_count();
 #else
   return -1;
