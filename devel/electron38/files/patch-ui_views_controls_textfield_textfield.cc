--- ui/views/controls/textfield/textfield.cc.orig	2025-08-26 20:49:50 UTC
+++ ui/views/controls/textfield/textfield.cc
@@ -86,7 +86,7 @@
 #include "base/win/win_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/text_input_flags.h"
 #include "ui/linux/linux_ui.h"
@@ -183,7 +183,7 @@ bool IsControlKeyModifier(int flags) {
 // Control-modified key combination, but we cannot extend it to other platforms
 // as Control has different meanings and behaviors.
 // https://crrev.com/2580483002/#msg46
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return flags & ui::EF_CONTROL_DOWN;
 #else
   return false;
@@ -791,7 +791,7 @@ bool Textfield::OnKeyPressed(const ui::KeyEvent& event
     return handled;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!handled) {
     if (auto* linux_ui = ui::LinuxUi::instance()) {
       const auto command =
@@ -976,7 +976,7 @@ bool Textfield::SkipDefaultKeyEventProcessing(const ui
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Skip any accelerator handling that conflicts with custom keybindings.
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     if (IsTextEditCommandEnabled(linux_ui->GetTextEditCommandForEvent(
@@ -2065,7 +2065,7 @@ bool Textfield::ShouldDoLearning() {
   return false;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/41452689): Implement this method to support Korean IME
 // reconversion feature on native text fields (e.g. find bar).
 bool Textfield::SetCompositionFromExistingText(
@@ -2581,7 +2581,7 @@ ui::TextEditCommand Textfield::GetCommandForKeyEvent(
 #endif
         return ui::TextEditCommand::DELETE_BACKWARD;
       }
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift) {
         return ui::TextEditCommand::DELETE_TO_BEGINNING_OF_LINE;
@@ -2589,7 +2589,7 @@ ui::TextEditCommand Textfield::GetCommandForKeyEvent(
 #endif
       return ui::TextEditCommand::DELETE_WORD_BACKWARD;
     case ui::VKEY_DELETE:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift && control) {
         return ui::TextEditCommand::DELETE_TO_END_OF_LINE;
