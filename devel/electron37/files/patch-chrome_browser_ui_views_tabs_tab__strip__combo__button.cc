--- chrome/browser/ui/views/tabs/tab_strip_combo_button.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/views/tabs/tab_strip_combo_button.cc
@@ -94,7 +94,7 @@ TabStripComboButton::TabStripComboButton(BrowserWindow
       base::BindRepeating(&TabStripComboButton::OnNewTabButtonStateChanged,
                           base::Unretained(this))));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The New Tab Button can be middle-clicked on Linux.
   new_tab_button->SetTriggerableEventFlags(
       new_tab_button->GetTriggerableEventFlags() | ui::EF_MIDDLE_MOUSE_BUTTON);
