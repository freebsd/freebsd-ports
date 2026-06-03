--- chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc
@@ -95,7 +95,7 @@ DialogText GetPromptDialogTextFromStatus(
       break;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           syncer::kReplaceSyncPromosWithSignInPromos) &&
       status.signin_status != collaboration::SigninStatus::kSigninDisabled) {
@@ -434,7 +434,7 @@ void CollaborationControllerDelegateDesktop::ShowError
       chrome::ShowBrowserModal(browser_, std::move(dialog_model));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void CollaborationControllerDelegateDesktop::
     MaybeShowSignInUiForHistorySyncOptin() {
   collaboration::ServiceStatus status = GetServiceStatus();
@@ -519,7 +519,7 @@ void CollaborationControllerDelegateDesktop::
   }
 
   AccountInfo account_for_promo =
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       signin_ui_util::GetSingleAccountForPromos(
           IdentityManagerFactory::GetForProfile(browser_->profile()));
 #else
@@ -554,7 +554,7 @@ void CollaborationControllerDelegateDesktop::
               .SetLabel(dialog_text.ok_button_text)
               .SetEnabled(true));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           syncer::kReplaceSyncPromosWithSignInPromos)) {
     dialog_builder.SetFootnote(ui::DialogModelLabel(dialog_text.footnote));
@@ -605,7 +605,7 @@ void CollaborationControllerDelegateDesktop::OnPromptD
         .Run(CollaborationControllerDelegate::Outcome::kSuccess);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           syncer::kReplaceSyncPromosWithSignInPromos)) {
     MaybeShowSignInUiForHistorySyncOptin();
