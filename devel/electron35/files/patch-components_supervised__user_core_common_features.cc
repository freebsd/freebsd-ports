--- components/supervised_user/core/common/features.cc.orig	2025-03-24 20:50:14 UTC
+++ components/supervised_user/core/common/features.cc
@@ -68,7 +68,7 @@ BASE_FEATURE(kUpdatedSupervisedUserExtensionApprovalSt
              "UpdatedSupervisedUserExtensionApprovalStrings",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -83,7 +83,7 @@ bool IsSupervisedUserSkipParentApprovalToInstallExtens
 #if BUILDFLAG(IS_CHROMEOS)
   return base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool skipParentApprovalEnabled = base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
   bool permissionExtensionsForSupervisedUsersEnabled =
@@ -104,7 +104,7 @@ BASE_FEATURE(kCustomProfileStringsForSupervisedUsers,
              "CustomProfileStringsForSupervisedUsers",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 BASE_FEATURE(kShowKiteForSupervisedUsers,
              "ShowKiteForSupervisedUsers",
@@ -113,13 +113,13 @@ BASE_FEATURE(kForceSafeSearchForUnauthenticatedSupervi
 
 BASE_FEATURE(kForceSafeSearchForUnauthenticatedSupervisedUsers,
              "ForceSafeSearchForUnauthenticatedSupervisedUsers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableSupervisedUserVersionSignOutDialog,
              "EnableSupervisedUserVersionSignOutDialog",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -141,7 +141,7 @@ BASE_FEATURE(kUncredentialedFilteringFallbackForSuperv
 // platform #defines.
 BASE_FEATURE(kUncredentialedFilteringFallbackForSupervisedUsers,
              "UncredentialedFilteringFallbackForSupervisedUsers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
