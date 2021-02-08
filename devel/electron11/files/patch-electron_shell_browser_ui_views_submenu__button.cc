--- electron/shell/browser/ui/views/submenu_button.cc.orig	2021-01-22 23:55:24 UTC
+++ electron/shell/browser/ui/views/submenu_button.cc
@@ -27,7 +27,7 @@ SubmenuButton::SubmenuButton(views::ButtonListener* bu
           button_listener,
           gfx::RemoveAcceleratorChar(title, '&', nullptr, nullptr)),
       background_color_(background_color) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Dont' use native style border.
   SetBorder(CreateDefaultBorder());
 #endif
