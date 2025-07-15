--- chrome/browser/ui/views/frame/system_menu_model_builder.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/views/frame/system_menu_model_builder.cc
@@ -75,7 +75,7 @@ void SystemMenuModelBuilder::BuildSystemMenuForBrowser
 
 void SystemMenuModelBuilder::BuildSystemMenuForBrowserWindow(
     ui::SimpleMenuModel* model) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddItemWithStringId(IDC_MINIMIZE_WINDOW, IDS_MINIMIZE_WINDOW_MENU);
   model->AddItemWithStringId(IDC_MAXIMIZE_WINDOW, IDS_MAXIMIZE_WINDOW_MENU);
   model->AddItemWithStringId(IDC_RESTORE_WINDOW, IDS_RESTORE_WINDOW_MENU);
@@ -101,7 +101,7 @@ void SystemMenuModelBuilder::BuildSystemMenuForBrowser
     model->AddSeparator(ui::NORMAL_SEPARATOR);
     model->AddItemWithStringId(IDC_TASK_MANAGER_CONTEXT_MENU, IDS_TASK_MANAGER);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   bool supports_server_side_decorations = true;
 #if BUILDFLAG(IS_OZONE) && !BUILDFLAG(IS_CHROMEOS)
@@ -175,7 +175,7 @@ void SystemMenuModelBuilder::BuildSystemMenuForAppOrPo
     model->AddSeparator(ui::NORMAL_SEPARATOR);
     model->AddItemWithStringId(IDC_TASK_MANAGER, IDS_TASK_MANAGER);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   model->AddItemWithStringId(IDC_CLOSE_WINDOW, IDS_CLOSE);
 #endif
