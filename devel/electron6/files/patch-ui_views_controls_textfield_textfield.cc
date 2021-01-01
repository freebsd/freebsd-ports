--- ui/views/controls/textfield/textfield.cc.orig	2019-09-10 11:14:40 UTC
+++ ui/views/controls/textfield/textfield.cc
@@ -62,7 +62,7 @@
 #include "base/win/win_util.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "base/strings/utf_string_conversions.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -165,14 +165,14 @@ ui::TextEditCommand GetCommandForKeyEvent(const ui::Ke
     case ui::VKEY_BACK:
       if (!control)
         return ui::TextEditCommand::DELETE_BACKWARD;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return ui::TextEditCommand::DELETE_TO_BEGINNING_OF_LINE;
 #endif
       return ui::TextEditCommand::DELETE_WORD_BACKWARD;
     case ui::VKEY_DELETE:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift && control)
         return ui::TextEditCommand::DELETE_TO_END_OF_LINE;
@@ -240,7 +240,7 @@ bool IsControlKeyModifier(int flags) {
 // Control-modified key combination, but we cannot extend it to other platforms
 // as Control has different meanings and behaviors.
 // https://crrev.com/2580483002/#msg46
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return flags & ui::EF_CONTROL_DOWN;
 #else
   return false;
@@ -675,7 +675,7 @@ bool Textfield::OnMousePressed(const ui::MouseEvent& e
 #endif
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (!handled && !had_focus && event.IsOnlyMiddleMouseButton())
     RequestFocusWithPointer(ui::EventPointerType::POINTER_TYPE_MOUSE);
 #endif
@@ -721,7 +721,7 @@ bool Textfield::OnKeyPressed(const ui::KeyEvent& event
   if (!textfield)
     return handled;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -890,7 +890,7 @@ void Textfield::AboutToRequestFocusFromTabTraversal(bo
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Skip any accelerator handling that conflicts with custom keybindings.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
@@ -2109,7 +2109,7 @@ bool Textfield::PasteSelectionClipboard() {
 }
 
 void Textfield::UpdateSelectionClipboard() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (text_input_type_ != ui::TEXT_INPUT_TYPE_PASSWORD) {
     ui::ScopedClipboardWriter(ui::CLIPBOARD_TYPE_SELECTION)
         .WriteText(GetSelectedText());
