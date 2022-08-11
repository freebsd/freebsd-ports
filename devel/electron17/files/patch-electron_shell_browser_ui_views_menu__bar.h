--- electron/shell/browser/ui/views/menu_bar.h.orig	2022-05-11 15:32:29 UTC
+++ electron/shell/browser/ui/views/menu_bar.h
@@ -79,7 +79,7 @@ class MenuBar : public views::AccessiblePaneView,
   View* FindAccelChild(char16_t key);
 
   SkColor background_color_;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SkColor enabled_color_;
   SkColor disabled_color_;
 #endif
