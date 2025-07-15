--- chrome/browser/ui/signin/signin_view_controller_delegate.h.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/signin/signin_view_controller_delegate.h
@@ -48,7 +48,7 @@ class SigninViewControllerDelegate {
       SyncConfirmationStyle style,
       bool is_sync_promo);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns a platform-specific SigninViewControllerDelegate instance that
   // displays the modal history sync opt in dialog. The returned object should
   // delete itself when the window it's managing is closed.
@@ -87,7 +87,7 @@ class SigninViewControllerDelegate {
       SignoutConfirmationCallback callback);
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns a platform-specific SigninViewContolllerDelegate instance that
   // displays the managed user notice modal dialog. The returned object
   // should delete itself when the window it's managing is closed.
