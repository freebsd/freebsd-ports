--- electron/shell/browser/electron_browser_main_parts.h.orig	2022-08-03 15:31:58 UTC
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -61,7 +61,7 @@ class ViewsDelegate;
 class ViewsDelegateMac;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 class DarkThemeObserver;
 #endif
 
@@ -122,7 +122,7 @@ class ElectronBrowserMainParts : public content::Brows
       const scoped_refptr<base::SingleThreadTaskRunner>& task_runner);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void DetectOzonePlatform();
 #endif
 
@@ -143,7 +143,7 @@ class ElectronBrowserMainParts : public content::Brows
   std::unique_ptr<display::Screen> screen_;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Used to notify the native theme of changes to dark mode.
   std::unique_ptr<DarkThemeObserver> dark_theme_observer_;
 #endif
