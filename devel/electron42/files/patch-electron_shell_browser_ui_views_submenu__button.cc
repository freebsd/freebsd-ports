--- electron/shell/browser/ui/views/submenu_button.cc.orig	2026-01-15 18:39:20 UTC
+++ electron/shell/browser/ui/views/submenu_button.cc
@@ -23,7 +23,7 @@ SubmenuButton::SubmenuButton(PressedCallback callback,
                              const SkColor& background_color)
     : views::MenuButton(std::move(callback), gfx::RemoveAccelerator(title)),
       background_color_(background_color) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Don't use native style border.
   SetBorder(CreateDefaultBorder());
 #endif
