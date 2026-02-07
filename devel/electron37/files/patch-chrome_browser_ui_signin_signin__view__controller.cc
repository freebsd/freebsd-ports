--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -444,7 +444,7 @@ void SigninViewController::ShowModalSyncConfirmationDi
       GetOnModalDialogClosedCallback());
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SigninViewController::ShowModalHistorySyncOptInDialog() {
   CHECK(base::FeatureList::IsEnabled(switches::kEnableHistorySyncOptin));
   CloseModalSignin();
@@ -457,7 +457,7 @@ void SigninViewController::ShowModalManagedUserNoticeD
 void SigninViewController::ShowModalManagedUserNoticeDialog(
     std::unique_ptr<signin::EnterpriseProfileCreationDialogParams>
         create_param) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
