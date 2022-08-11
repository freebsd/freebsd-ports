--- chrome/browser/signin/primary_account_policy_manager.h.orig	2022-05-25 04:00:49 UTC
+++ chrome/browser/signin/primary_account_policy_manager.h
@@ -44,7 +44,7 @@ class PrimaryAccountPolicyManager : public KeyedServic
       Profile* profile,
       signin_metrics::ProfileSignout clear_primary_account_source);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   class DeleteProfileDialogManager;
 
   // SHows the delete profile dialog.
@@ -68,7 +68,7 @@ class PrimaryAccountPolicyManager : public KeyedServic
   // profile-specific local prefs (like kGoogleServicesUsernamePattern).
   PrefChangeRegistrar local_state_pref_registrar_;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   std::unique_ptr<DeleteProfileDialogManager> delete_profile_dialog_manager_;
   bool hide_ui_for_testing_ = false;
 #endif
