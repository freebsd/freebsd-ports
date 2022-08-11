--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h.orig	2022-05-11 07:16:49 UTC
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.h
@@ -64,7 +64,7 @@ class SigninViewControllerDelegateViews
       signin_metrics::ReauthAccessPoint);
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   static std::unique_ptr<views::WebView> CreateEnterpriseConfirmationWebView(
       Browser* browser,
       const AccountInfo& account_info,
