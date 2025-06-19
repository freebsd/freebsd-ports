--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-06-09 18:58:16 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2584,7 +2584,7 @@ void BrowserView::TabDraggingStatusChanged(bool is_dra
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   GetContentsWebView()->SetFastResize(is_dragging);
   if (multi_contents_view_) {
     multi_contents_view_->GetInactiveContentsView()->SetFastResize(is_dragging);
@@ -5828,7 +5828,7 @@ void BrowserView::MaybeShowSupervisedUserProfileSignIn
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
