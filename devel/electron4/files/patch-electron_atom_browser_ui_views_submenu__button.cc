--- electron/atom/browser/ui/views/submenu_button.cc.orig	2019-03-16 12:44:12 UTC
+++ electron/atom/browser/ui/views/submenu_button.cc
@@ -26,7 +26,7 @@ SubmenuButton::SubmenuButton(const base::string16& tit
                         menu_button_listener,
                         false),
       background_color_(background_color) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Dont' use native style border.
   SetBorder(CreateDefaultBorder());
 #endif
