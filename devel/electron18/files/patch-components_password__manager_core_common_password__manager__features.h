--- components/password_manager/core/common/password_manager_features.h.orig	2022-05-19 05:17:40 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -27,7 +27,7 @@ extern const base::Feature kEnablePasswordsAccountStor
 extern const base::Feature KEnablePasswordGenerationForClearTextFields;
 extern const base::Feature kFillingAcrossAffiliatedWebsites;
 extern const base::Feature kFillOnAccountSelect;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kForceInitialSyncWhenDecryptionFails;
 #endif
 extern const base::Feature kInferConfirmationPasswordField;
@@ -46,11 +46,11 @@ extern const base::Feature kPasswordScriptsFetching;
 extern const base::Feature kRecoverFromNeverSaveAndroid;
 extern const base::Feature kReparseServerPredictionsFollowingFormChange;
 extern const base::Feature kSecondaryServerFieldPredictions;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSkipUndecryptablePasswords;
 #endif
 extern const base::Feature kSupportForAddPasswordsInSettings;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSyncUndecryptablePasswordsLinux;
 #endif
 #if BUILDFLAG(IS_ANDROID)
