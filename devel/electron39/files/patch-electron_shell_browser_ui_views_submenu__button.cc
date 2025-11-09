--- electron/shell/browser/ui/views/submenu_button.cc.orig	2025-05-07 07:36:13 UTC
+++ electron/shell/browser/ui/views/submenu_button.cc
@@ -22,7 +22,7 @@ SubmenuButton::SubmenuButton(PressedCallback callback,
                              const SkColor& background_color)
     : views::MenuButton(std::move(callback), gfx::RemoveAccelerator(title)),
       background_color_(background_color) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Don't use native style border.
   SetBorder(CreateDefaultBorder());
 #endif
