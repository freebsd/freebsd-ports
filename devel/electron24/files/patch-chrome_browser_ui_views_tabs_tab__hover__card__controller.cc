--- chrome/browser/ui/views/tabs/tab_hover_card_controller.cc.orig	2023-03-30 00:33:44 UTC
+++ chrome/browser/ui/views/tabs/tab_hover_card_controller.cc
@@ -78,7 +78,7 @@ void FixWidgetStackOrder(views::Widget* widget, const 
     return;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Ensure the hover card Widget assumes the highest z-order to avoid occlusion
   // by other secondary UI Widgets (such as the omnibox Widget, see
   // crbug.com/1226536).
