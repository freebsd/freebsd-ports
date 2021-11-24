--- electron/shell/browser/ui/views/submenu_button.cc.orig	2021-04-20 23:32:33 UTC
+++ electron/shell/browser/ui/views/submenu_button.cc
@@ -25,7 +25,7 @@ SubmenuButton::SubmenuButton(PressedCallback callback,
                              const SkColor& background_color)
     : views::MenuButton(callback, gfx::RemoveAccelerator(title)),
       background_color_(background_color) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Dont' use native style border.
   SetBorder(CreateDefaultBorder());
 #endif
