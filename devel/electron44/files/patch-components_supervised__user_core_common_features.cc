--- components/supervised_user/core/common/features.cc.orig	2026-06-23 23:37:18 UTC
+++ components/supervised_user/core/common/features.cc
@@ -30,7 +30,7 @@ BASE_FEATURE(kAllowSubframeLocalWebApprovals,
 #endif
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const int kLocalWebApprovalBottomSheetLoadTimeoutDefaultValueMs = 5000;
 
 const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs{
@@ -68,7 +68,7 @@ bool IsLocalWebApprovalsEnabledForSubframes() {
   return base::FeatureList::IsEnabled(kAllowSubframeLocalWebApprovals);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableSupervisedUserVersionSignOutDialog,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
