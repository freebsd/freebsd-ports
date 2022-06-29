--- chrome/browser/ui/views/tabs/tab_hover_card_controller.cc.orig	2022-05-25 04:00:50 UTC
+++ chrome/browser/ui/views/tabs/tab_hover_card_controller.cc
@@ -71,7 +71,7 @@ GetMemoryPressureOverride() {
 // Fetches the Omnibox drop-down widget, or returns null if the drop-down is
 // not visible.
 void FixWidgetStackOrder(views::Widget* widget, const Browser* browser) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Ensure the hover card Widget assumes the highest z-order to avoid occlusion
   // by other secondary UI Widgets (such as the omnibox Widget, see
   // crbug.com/1226536).
