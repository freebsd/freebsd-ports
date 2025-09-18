--- chrome/browser/ui/task_manager/task_manager_table_model.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/ui/task_manager/task_manager_table_model.cc
@@ -376,7 +376,7 @@ TaskManagerTableModel::~TaskManagerTableModel() {
   // Note: system_total_time_ is used for both since there is no functional
   // difference between browser & system (they are essentially the same tab).
   // Instead, the data is routed to the platform appropriate bucket.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   task_manager::RecordTabSwitchEvent(CategoryRecord::kBrowser,
                                      system_total_time_);
 #elif BUILDFLAG(IS_CHROMEOS)
@@ -509,7 +509,7 @@ std::u16string TaskManagerTableModel::GetText(size_t r
                  ? stringifier_->backgrounded_string()
                  : stringifier_->foregrounded_string();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int fd_count = observed_task_manager()->GetOpenFdCount(tasks_[row]);
       return fd_count >= 0 ? base::FormatNumber(fd_count)
@@ -667,7 +667,7 @@ int TaskManagerTableModel::CompareValues(size_t row1,
       return BooleanCompare(is_proc1_bg, is_proc2_bg);
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int proc1_fd_count =
           observed_task_manager()->GetOpenFdCount(tasks_[row1]);
@@ -979,7 +979,7 @@ void TaskManagerTableModel::UpdateRefreshTypes(int col
       type = REFRESH_TYPE_KEEPALIVE_COUNT;
       break;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN:
       type = REFRESH_TYPE_FD_COUNT;
       break;
