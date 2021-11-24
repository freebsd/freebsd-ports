--- electron/shell/browser/ui/views/menu_bar.h.orig	2021-04-22 08:43:16 UTC
+++ electron/shell/browser/ui/views/menu_bar.h
@@ -87,7 +87,7 @@ class MenuBar : public views::AccessiblePaneView,
 
   void RefreshColorCache();
   SkColor background_color_;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SkColor enabled_color_;
   SkColor disabled_color_;
 #endif
