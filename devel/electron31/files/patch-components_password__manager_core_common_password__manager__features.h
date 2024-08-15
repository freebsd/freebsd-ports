--- components/password_manager/core/common/password_manager_features.h.orig	2023-11-29 21:39:58 UTC
+++ components/password_manager/core/common/password_manager_features.h
@@ -19,7 +19,7 @@ BASE_DECLARE_FEATURE(kEnableOverwritingPlaceholderUser
 // alongside the definition of their values in the .cc file.
 BASE_DECLARE_FEATURE(kEnableOverwritingPlaceholderUsernames);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kForceInitialSyncWhenDecryptionFails);
 #endif
 BASE_DECLARE_FEATURE(kForgotPasswordFormSupport);
