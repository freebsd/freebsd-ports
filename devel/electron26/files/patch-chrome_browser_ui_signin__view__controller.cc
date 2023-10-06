--- chrome/browser/ui/signin_view_controller.cc.orig	2023-08-10 01:48:36 UTC
+++ chrome/browser/ui/signin_view_controller.cc
@@ -275,7 +275,7 @@ void SigninViewController::ShowModalEnterpriseConfirma
     bool show_link_data_option,
     signin::SigninChoiceCallback callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateEnterpriseConfirmationDelegate(
