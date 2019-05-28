--- chrome/browser/ui/toolbar/app_menu_model.cc.orig	2019-03-15 06:37:06 UTC
+++ chrome/browser/ui/toolbar/app_menu_model.cc
@@ -664,7 +664,7 @@ bool AppMenuModel::IsCommandIdVisible(int command_id) 
     case IDC_UPGRADE_DIALOG:
       return browser_defaults::kShowUpgradeMenuItem &&
           UpgradeDetector::GetInstance()->notify_upgrade();
-#if !defined(OS_LINUX) || defined(USE_AURA)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(USE_AURA)
     case IDC_BOOKMARK_PAGE:
       return !chrome::ShouldRemoveBookmarkThisPageUI(browser_->profile());
     case IDC_BOOKMARK_ALL_TABS:
