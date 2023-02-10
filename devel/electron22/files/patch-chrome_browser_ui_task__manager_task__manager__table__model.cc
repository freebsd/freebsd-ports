--- chrome/browser/ui/task_manager/task_manager_table_model.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/ui/task_manager/task_manager_table_model.cc
@@ -455,7 +455,7 @@ std::u16string TaskManagerTableModel::GetText(size_t r
           ? stringifier_->backgrounded_string()
           : stringifier_->foregrounded_string();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int fd_count = observed_task_manager()->GetOpenFdCount(tasks_[row]);
       return fd_count >= 0 ? base::FormatNumber(fd_count)
@@ -622,7 +622,7 @@ int TaskManagerTableModel::CompareValues(size_t row1,
       return BooleanCompare(is_proc1_bg, is_proc2_bg);
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int proc1_fd_count =
           observed_task_manager()->GetOpenFdCount(tasks_[row1]);
@@ -796,7 +796,7 @@ void TaskManagerTableModel::UpdateRefreshTypes(int col
       type = REFRESH_TYPE_KEEPALIVE_COUNT;
       break;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN:
       type = REFRESH_TYPE_FD_COUNT;
       break;
