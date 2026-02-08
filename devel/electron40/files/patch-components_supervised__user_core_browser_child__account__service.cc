--- components/supervised_user/core/browser/child_account_service.cc.orig	2025-08-26 20:49:50 UTC
+++ components/supervised_user/core/browser/child_account_service.cc
@@ -170,7 +170,7 @@ void ChildAccountService::UpdateForceGoogleSafeSearch(
 void ChildAccountService::UpdateForceGoogleSafeSearch() {
 // On platforms without web sign-out (where the primary account is always
 // authenticated), there's no need to force SafeSearch.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool is_subject_to_parental_controls =
       IsPrimaryAccountSubjectToParentalControls(identity_manager_) ==
       signin::Tribool::kTrue;
