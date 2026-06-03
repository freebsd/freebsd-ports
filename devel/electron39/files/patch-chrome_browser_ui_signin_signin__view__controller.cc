--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -476,7 +476,7 @@ void SigninViewController::ShowModalSyncConfirmationDi
       GetOnModalDialogClosedCallback());
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SigninViewController::ShowModalHistorySyncOptInDialog(
     HistorySyncOptinHelper::FlowCompletedCallback callback) {
   CHECK(
@@ -493,7 +493,7 @@ void SigninViewController::ShowModalManagedUserNoticeD
 void SigninViewController::ShowModalManagedUserNoticeDialog(
     std::unique_ptr<signin::EnterpriseProfileCreationDialogParams>
         create_param) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(
