--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h
@@ -77,7 +77,7 @@ class SigninViewControllerDelegateViews
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<views::WebView> CreateEnterpriseConfirmationWebView(
       Browser* browser,
       const AccountInfo& account_info,
