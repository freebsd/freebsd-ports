--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2023-10-19 19:58:07 UTC
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -253,7 +253,7 @@ void SigninViewController::ShowModalEnterpriseConfirma
     bool show_link_data_option,
     signin::SigninChoiceCallback callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateEnterpriseConfirmationDelegate(
