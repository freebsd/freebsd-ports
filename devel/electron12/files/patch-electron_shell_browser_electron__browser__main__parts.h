--- electron/shell/browser/electron_browser_main_parts.h.orig	2021-04-22 08:27:19 UTC
+++ electron/shell/browser/electron_browser_main_parts.h
@@ -58,7 +58,7 @@ class ViewsDelegate;
 class ViewsDelegateMac;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class DarkThemeObserver;
 #endif
 
@@ -129,7 +129,7 @@ class ElectronBrowserMainParts : public content::Brows
   std::unique_ptr<ui::GtkUiDelegate> gtk_ui_delegate_;
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Used to notify the native theme of changes to dark mode.
   std::unique_ptr<DarkThemeObserver> dark_theme_observer_;
 #endif
