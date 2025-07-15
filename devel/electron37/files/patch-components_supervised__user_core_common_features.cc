--- components/supervised_user/core/common/features.cc.orig	2025-06-30 07:04:30 UTC
+++ components/supervised_user/core/common/features.cc
@@ -37,7 +37,7 @@ BASE_FEATURE(kAllowSubframeLocalWebApprovals,
 #endif
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const int kLocalWebApprovalBottomSheetLoadTimeoutDefaultValueMs = 5000;
 
 const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs{
@@ -46,7 +46,7 @@ const base::FeatureParam<int> kLocalWebApprovalBottomS
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableLocalWebApprovalErrorDialog,
              "EnableLocalWebApprovalErrorDialog",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -89,7 +89,7 @@ bool IsLocalWebApprovalsEnabledForSubframes() {
   return base::FeatureList::IsEnabled(kAllowSubframeLocalWebApprovals);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kCustomProfileStringsForSupervisedUsers,
              "CustomProfileStringsForSupervisedUsers",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -101,13 +101,13 @@ BASE_FEATURE(kForceSafeSearchForUnauthenticatedSupervi
 
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
@@ -119,7 +119,7 @@ BASE_FEATURE(kUncredentialedFilteringFallbackForSuperv
 // platform #defines.
 BASE_FEATURE(kUncredentialedFilteringFallbackForSupervisedUsers,
              "UncredentialedFilteringFallbackForSupervisedUsers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
