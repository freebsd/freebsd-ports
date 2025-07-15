--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2740,7 +2740,7 @@ void BrowserView::TabDraggingStatusChanged(bool is_dra
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   GetContentsWebView()->SetFastResize(is_dragging);
   if (multi_contents_view_) {
     multi_contents_view_->GetInactiveContentsView()->SetFastResize(is_dragging);
@@ -6044,7 +6044,7 @@ void BrowserView::MaybeShowSupervisedUserProfileSignIn
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
