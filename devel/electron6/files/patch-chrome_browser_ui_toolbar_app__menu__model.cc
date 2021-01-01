--- chrome/browser/ui/toolbar/app_menu_model.cc.orig	2019-09-10 11:13:43 UTC
+++ chrome/browser/ui/toolbar/app_menu_model.cc
@@ -671,7 +671,7 @@ bool AppMenuModel::IsCommandIdVisible(int command_id) 
       return app_menu_icon_controller_->GetTypeAndSeverity().type ==
              AppMenuIconController::IconType::UPGRADE_NOTIFICATION;
     }
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
     case IDC_BOOKMARK_PAGE:
       return !chrome::ShouldRemoveBookmarkThisPageUI(browser_->profile());
     case IDC_BOOKMARK_ALL_TABS:
