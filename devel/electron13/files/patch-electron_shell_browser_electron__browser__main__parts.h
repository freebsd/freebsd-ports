--- electron/shell/browser/electron_browser_main_parts.h.orig	2021-10-27 21:25:28 UTC
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -63,7 +63,7 @@ class ViewsDelegate;
 class ViewsDelegateMac;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class DarkThemeObserver;
 #endif
 
@@ -140,7 +140,7 @@ class ElectronBrowserMainParts : public content::Brows
   std::unique_ptr<ui::GtkUiDelegate> gtk_ui_delegate_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Used to notify the native theme of changes to dark mode.
   std::unique_ptr<DarkThemeObserver> dark_theme_observer_;
 #endif
