--- chrome/browser/ui/signin_view_controller_delegate.h.orig	2022-05-19 05:17:38 UTC
+++ chrome/browser/ui/signin_view_controller_delegate.h
@@ -74,7 +74,7 @@ class SigninViewControllerDelegate {
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Returns a platform-specific SigninViewContolllerDelegate instance that
   // displays the enterprise confirmation modal dialog. The returned object
   // should delete itself when the window it's managing is closed.
