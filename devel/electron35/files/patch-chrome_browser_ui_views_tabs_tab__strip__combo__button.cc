--- chrome/browser/ui/views/tabs/tab_strip_combo_button.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/ui/views/tabs/tab_strip_combo_button.cc
@@ -96,7 +96,7 @@ TabStripComboButton::TabStripComboButton(BrowserWindow
       base::BindRepeating(&TabStripComboButton::OnNewTabButtonStateChanged,
                           base::Unretained(this))));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The New Tab Button can be middle-clicked on Linux.
   new_tab_button->SetTriggerableEventFlags(
       new_tab_button->GetTriggerableEventFlags() | ui::EF_MIDDLE_MOUSE_BUTTON);
