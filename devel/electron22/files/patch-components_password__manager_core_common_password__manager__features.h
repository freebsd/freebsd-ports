--- components/password_manager/core/common/password_manager_features.h.orig	2022-11-30 08:12:58 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -38,7 +38,7 @@ BASE_DECLARE_FEATURE(kEnablePasswordGenerationForClear
 BASE_DECLARE_FEATURE(kEnablePasswordManagerWithinFencedFrame);
 BASE_DECLARE_FEATURE(kFillingAcrossAffiliatedWebsites);
 BASE_DECLARE_FEATURE(kFillOnAccountSelect);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kForceInitialSyncWhenDecryptionFails);
 #endif
 BASE_DECLARE_FEATURE(kInferConfirmationPasswordField);
@@ -65,10 +65,10 @@ BASE_DECLARE_FEATURE(kPasswordScriptsFetching);
 BASE_DECLARE_FEATURE(kPasswordsGrouping);
 BASE_DECLARE_FEATURE(kPasswordStrengthIndicator);
 BASE_DECLARE_FEATURE(kRecoverFromNeverSaveAndroid);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSkipUndecryptablePasswords);
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSyncUndecryptablePasswordsLinux);
 #endif
 #if BUILDFLAG(IS_ANDROID)
