--- components/password_manager/core/common/password_manager_features.h.orig	2023-05-25 00:41:51 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -44,7 +44,7 @@ BASE_DECLARE_FEATURE(kFillingAcrossAffiliatedWebsites)
 BASE_DECLARE_FEATURE(kFillingAcrossGroupedSites);
 BASE_DECLARE_FEATURE(kFillOnAccountSelect);
 BASE_DECLARE_FEATURE(kPasswordManagerLogToTerminal);
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kForceInitialSyncWhenDecryptionFails);
 #endif
 BASE_DECLARE_FEATURE(kInferConfirmationPasswordField);
@@ -74,7 +74,7 @@ BASE_DECLARE_FEATURE(kRecoverFromNeverSaveAndroid);
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_IOS)  // Desktop
 BASE_DECLARE_FEATURE(kRevampedPasswordManagementBubble);
 #endif
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSkipUndecryptablePasswords);
 #endif
 #if BUILDFLAG(IS_ANDROID)
