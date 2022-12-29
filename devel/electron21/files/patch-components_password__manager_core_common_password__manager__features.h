--- components/password_manager/core/common/password_manager_features.h.orig	2022-09-24 10:57:32 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -37,7 +37,7 @@ extern const base::Feature KEnablePasswordGenerationFo
 extern const base::Feature kEnablePasswordManagerWithinFencedFrame;
 extern const base::Feature kFillingAcrossAffiliatedWebsites;
 extern const base::Feature kFillOnAccountSelect;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kForceInitialSyncWhenDecryptionFails;
 #endif
 extern const base::Feature kInferConfirmationPasswordField;
@@ -63,10 +63,10 @@ extern const base::Feature kPasswordReuseDetectionEnab
 extern const base::Feature kPasswordScriptsFetching;
 extern const base::Feature kPasswordStrengthIndicator;
 extern const base::Feature kRecoverFromNeverSaveAndroid;
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSkipUndecryptablePasswords;
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const base::Feature kSyncUndecryptablePasswordsLinux;
 #endif
 #if BUILDFLAG(IS_ANDROID)
