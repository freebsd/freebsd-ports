--- chrome/browser/ui/views/frame/system_menu_model_delegate.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/views/frame/system_menu_model_delegate.cc
@@ -20,7 +20,7 @@
 #include "chromeos/ui/frame/desks/move_to_desks_menu_model.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/pref_names.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -39,7 +39,7 @@ bool SystemMenuModelDelegate::IsCommandIdChecked(int c
 SystemMenuModelDelegate::~SystemMenuModelDelegate() = default;
 
 bool SystemMenuModelDelegate::IsCommandIdChecked(int command_id) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_id == IDC_USE_SYSTEM_TITLE_BAR) {
     PrefService* prefs = browser_->profile()->GetPrefs();
     return !prefs->GetBoolean(prefs::kUseCustomChromeFrame);
@@ -65,7 +65,7 @@ bool SystemMenuModelDelegate::IsCommandIdVisible(int c
 }
 
 bool SystemMenuModelDelegate::IsCommandIdVisible(int command_id) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_maximized = browser_->window()->IsMaximized();
   switch (command_id) {
     case IDC_MAXIMIZE_WINDOW:
