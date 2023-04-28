--- components/password_manager/core/common/password_manager_features.h.orig	2023-02-01 18:43:16 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -36,7 +36,7 @@ BASE_DECLARE_FEATURE(kEnablePasswordGenerationForClear
 BASE_DECLARE_FEATURE(kEnablePasswordManagerWithinFencedFrame);
 BASE_DECLARE_FEATURE(kFillingAcrossAffiliatedWebsites);
 BASE_DECLARE_FEATURE(kFillOnAccountSelect);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kForceInitialSyncWhenDecryptionFails);
 #endif
 BASE_DECLARE_FEATURE(kInferConfirmationPasswordField);
@@ -62,7 +62,7 @@ BASE_DECLARE_FEATURE(kRecoverFromNeverSaveAndroid);
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)  // Desktop
 BASE_DECLARE_FEATURE(kRevampedPasswordManagementBubble);
 #endif
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSkipUndecryptablePasswords);
 #endif
 #if BUILDFLAG(IS_ANDROID)
