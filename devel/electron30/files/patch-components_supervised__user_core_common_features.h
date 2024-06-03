--- components/supervised_user/core/common/features.h.orig	2024-04-15 20:33:56 UTC
+++ components/supervised_user/core/common/features.h
@@ -23,7 +23,7 @@ BASE_DECLARE_FEATURE(
 BASE_DECLARE_FEATURE(
     kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop);
 #endif
 
