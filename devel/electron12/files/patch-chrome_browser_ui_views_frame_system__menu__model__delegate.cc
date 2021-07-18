--- chrome/browser/ui/views/frame/system_menu_model_delegate.cc.orig	2021-04-14 01:08:41 UTC
+++ chrome/browser/ui/views/frame/system_menu_model_delegate.cc
@@ -19,7 +19,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "chrome/common/pref_names.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -36,7 +36,7 @@ SystemMenuModelDelegate::~SystemMenuModelDelegate() {}
 bool SystemMenuModelDelegate::IsCommandIdChecked(int command_id) const {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   if (command_id == IDC_USE_SYSTEM_TITLE_BAR) {
     PrefService* prefs = browser_->profile()->GetPrefs();
     return !prefs->GetBoolean(prefs::kUseCustomChromeFrame);
@@ -52,7 +52,7 @@ bool SystemMenuModelDelegate::IsCommandIdEnabled(int c
 bool SystemMenuModelDelegate::IsCommandIdVisible(int command_id) const {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   bool is_maximized = browser_->window()->IsMaximized();
   switch (command_id) {
     case IDC_MAXIMIZE_WINDOW:
