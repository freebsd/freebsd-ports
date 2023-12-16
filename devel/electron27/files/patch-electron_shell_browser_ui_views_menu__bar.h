--- electron/shell/browser/ui/views/menu_bar.h.orig	2023-08-14 18:19:06 UTC
+++ electron/shell/browser/ui/views/menu_bar.h
@@ -83,7 +83,7 @@ class MenuBar : public views::AccessiblePaneView,
   View* FindAccelChild(char16_t key);
 
   SkColor background_color_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SkColor enabled_color_;
   SkColor disabled_color_;
 #endif
