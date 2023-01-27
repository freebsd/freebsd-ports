--- chrome/browser/ui/signin_view_controller.cc.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/ui/signin_view_controller.cc
@@ -273,7 +273,7 @@ void SigninViewController::ShowModalEnterpriseConfirma
     SkColor profile_color,
     signin::SigninChoiceCallback callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateEnterpriseConfirmationDelegate(
