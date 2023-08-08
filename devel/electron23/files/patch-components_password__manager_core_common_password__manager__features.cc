--- components/password_manager/core/common/password_manager_features.cc.orig	2023-02-01 18:43:16 UTC
+++ components/password_manager/core/common/password_manager_features.cc
@@ -80,7 +80,7 @@ BASE_FEATURE(kFillOnAccountSelect,
              "fill-on-account-select",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, initial sync will be forced during startup if the password
 // store has encryption service failures.
 BASE_FEATURE(kForceInitialSyncWhenDecryptionFails,
@@ -152,7 +152,7 @@ BASE_FEATURE(kPasswordChangeWellKnown,
 // Controls the ability to import passwords from Chrome's settings page.
 BASE_FEATURE(kPasswordImport,
              "PasswordImport",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -195,7 +195,7 @@ BASE_FEATURE(kPasswordStrengthIndicator,
              "PasswordStrengthIndicator",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Displays at least the decryptable and never saved logins in the password
 // manager
 BASE_FEATURE(kSkipUndecryptablePasswords,
