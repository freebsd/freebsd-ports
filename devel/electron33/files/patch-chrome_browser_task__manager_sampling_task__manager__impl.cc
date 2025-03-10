--- chrome/browser/task_manager/sampling/task_manager_impl.cc.orig	2024-08-14 20:54:38 UTC
+++ chrome/browser/task_manager/sampling/task_manager_impl.cc
@@ -219,7 +219,7 @@ int TaskManagerImpl::GetOpenFdCount(TaskId task_id) co
 }
 
 int TaskManagerImpl::GetOpenFdCount(TaskId task_id) const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return GetTaskGroupByTaskId(task_id)->open_fd_count();
 #else
   return -1;
