--- chrome/browser/ui/views/frame/system_menu_model_delegate.cc.orig	2023-08-10 01:48:37 UTC
+++ chrome/browser/ui/views/frame/system_menu_model_delegate.cc
@@ -21,7 +21,7 @@
 #include "chromeos/ui/frame/desks/move_to_desks_menu_model.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/pref_names.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -36,7 +36,7 @@ SystemMenuModelDelegate::SystemMenuModelDelegate(
 SystemMenuModelDelegate::~SystemMenuModelDelegate() {}
 
 bool SystemMenuModelDelegate::IsCommandIdChecked(int command_id) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_id == IDC_USE_SYSTEM_TITLE_BAR) {
     PrefService* prefs = browser_->profile()->GetPrefs();
     return !prefs->GetBoolean(prefs::kUseCustomChromeFrame);
@@ -58,7 +58,7 @@ bool SystemMenuModelDelegate::IsCommandIdEnabled(int c
 bool SystemMenuModelDelegate::IsCommandIdVisible(int command_id) const {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   bool is_maximized = browser_->window()->IsMaximized();
   switch (command_id) {
     case IDC_MAXIMIZE_WINDOW:
