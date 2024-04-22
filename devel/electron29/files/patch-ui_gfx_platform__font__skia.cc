--- ui/gfx/platform_font_skia.cc.orig	2024-02-21 00:21:15 UTC
+++ ui/gfx/platform_font_skia.cc
@@ -30,7 +30,7 @@
 #include "ui/gfx/system_fonts_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -168,7 +168,7 @@ void PlatformFontSkia::EnsuresDefaultFontIsInitialized
   weight = system_font.GetWeight();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, LinuxUi is used to query the native toolkit (e.g.
   // GTK) for the default UI font.
   if (const auto* linux_ui = ui::LinuxUi::instance()) {
