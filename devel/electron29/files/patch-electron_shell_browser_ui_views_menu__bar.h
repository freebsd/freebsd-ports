--- electron/shell/browser/ui/views/menu_bar.h.orig	2024-02-21 16:26:48 UTC
+++ electron/shell/browser/ui/views/menu_bar.h
@@ -85,7 +85,7 @@ class MenuBar : public views::AccessiblePaneView,
   View* FindAccelChild(char16_t key);
 
   SkColor background_color_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   SkColor enabled_color_;
   SkColor disabled_color_;
 #endif
