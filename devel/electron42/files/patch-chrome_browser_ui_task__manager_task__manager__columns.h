--- chrome/browser/ui/task_manager/task_manager_columns.h.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/ui/task_manager/task_manager_columns.h
@@ -264,7 +264,7 @@ inline constexpr std::array kColumns = {
                     .default_visibility = false},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     TableColumnData{.id = IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN,
                     .align = ui::TableColumn::RIGHT,
                     .width = -1,
