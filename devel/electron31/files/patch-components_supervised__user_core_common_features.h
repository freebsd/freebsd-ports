--- components/supervised_user/core/common/features.h.orig	2024-06-18 21:43:30 UTC
+++ components/supervised_user/core/common/features.h
@@ -25,7 +25,7 @@ BASE_DECLARE_FEATURE(kUpdatedSupervisedUserExtensionAp
 // Applies new informative strings during the parental extension approval flow.
 BASE_DECLARE_FEATURE(kUpdatedSupervisedUserExtensionApprovalStrings);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop);
 #endif
 
