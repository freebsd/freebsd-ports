--- chrome/browser/ui/views/tabs/common/tab_group_header_view.cc.orig	2026-08-24 20:59:34 UTC
+++ chrome/browser/ui/views/tabs/common/tab_group_header_view.cc
@@ -385,7 +385,7 @@ void TabGroupHeaderView::OnMouseExited(const ui::Mouse
 }
 
 void TabGroupHeaderView::OnMouseExited(const ui::MouseEvent& event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Bypasses the synchronous IsMouseHovered() check which can be stale on Linux
   // Wayland/X11 due to asynchronous cursor updates during mouse exit events.
   SetEditorBubbleButtonVisibilityOnHover(/*is_hovered=*/false);
