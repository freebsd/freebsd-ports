--- electron/shell/browser/ui/views/menu_bar.h.orig	2023-04-03 22:25:21 UTC
+++ electron/shell/browser/ui/views/menu_bar.h
@@ -82,7 +82,7 @@ class MenuBar : public views::AccessiblePaneView,
   View* FindAccelChild(char16_t key);
 
   SkColor background_color_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SkColor enabled_color_;
   SkColor disabled_color_;
 #endif
