--- chrome/browser/ui/views/frame/browser_view.cc.orig	2026-08-31 22:55:38 UTC
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2437,7 +2437,7 @@ void BrowserView::TabDraggingStatusChanged(bool is_dra
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   UpdateFastResizeForContentViews(is_dragging);
 
   if (!is_dragging) {
@@ -5764,7 +5764,7 @@ void BrowserView::MaybeShowSupervisedUserProfileSignIn
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
@@ -5775,7 +5775,7 @@ void BrowserView::MaybeShowSignInBenefitsIPH() {
 }
 
 void BrowserView::MaybeShowSignInBenefitsIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
