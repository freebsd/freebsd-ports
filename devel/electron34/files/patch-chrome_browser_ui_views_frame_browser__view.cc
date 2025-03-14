--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2356,7 +2356,7 @@ void BrowserView::TabDraggingStatusChanged(bool is_dra
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   contents_web_view_->SetFastResize(is_dragging);
   if (!is_dragging) {
     // When tab dragging is ended, we need to make sure the web contents get
