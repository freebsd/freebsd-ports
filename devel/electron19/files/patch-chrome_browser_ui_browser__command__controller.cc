--- chrome/browser/ui/browser_command_controller.cc.orig	2022-05-25 04:00:50 UTC
+++ chrome/browser/ui/browser_command_controller.cc
@@ -71,7 +71,7 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/events/keycodes/keyboard_codes.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/accessibility/accessibility_features.h"
 #endif
 
@@ -96,7 +96,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
 #endif
 
@@ -287,7 +287,7 @@ bool BrowserCommandController::IsReservedCommandOrKey(
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // If this key was registered by the user as a content editing hotkey, then
   // it is not reserved.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
@@ -523,7 +523,7 @@ bool BrowserCommandController::ExecuteCommandWithDispo
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     case IDC_MINIMIZE_WINDOW:
       browser_->window()->Minimize();
       break;
@@ -926,7 +926,7 @@ bool BrowserCommandController::ExecuteCommandWithDispo
       ExecuteUIDebugCommand(id, browser_);
       break;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case IDC_RUN_SCREEN_AI:
       RunScreenAi(browser_);
       break;
@@ -1088,7 +1088,7 @@ void BrowserCommandController::InitCommandState() {
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   command_updater_.UpdateCommandEnabled(IDC_MINIMIZE_WINDOW, true);
   command_updater_.UpdateCommandEnabled(IDC_MAXIMIZE_WINDOW, true);
   command_updater_.UpdateCommandEnabled(IDC_RESTORE_WINDOW, true);
@@ -1474,7 +1474,7 @@ void BrowserCommandController::UpdateCommandsForFullsc
   command_updater_.UpdateCommandEnabled(
       IDC_FOCUS_INACTIVE_POPUP_FOR_ACCESSIBILITY, main_not_fullscreen);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   command_updater_.UpdateCommandEnabled(IDC_RUN_SCREEN_AI,
                                         features::IsScreenAIEnabled());
 #endif
