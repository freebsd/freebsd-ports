--- electron/shell/browser/electron_browser_main_parts.h.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -61,7 +61,7 @@ class ViewsDelegate;
 class ViewsDelegateMac;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class DarkThemeObserver;
 #endif
 
@@ -139,7 +139,7 @@ class ElectronBrowserMainParts : public content::Brows
   std::unique_ptr<display::Screen> screen_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Used to notify the native theme of changes to dark mode.
   std::unique_ptr<DarkThemeObserver> dark_theme_observer_;
 #endif
