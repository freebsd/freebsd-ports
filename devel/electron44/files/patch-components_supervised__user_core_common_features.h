--- components/supervised_user/core/common/features.h.orig	2026-06-23 23:37:18 UTC
+++ components/supervised_user/core/common/features.h
@@ -20,12 +20,12 @@ BASE_DECLARE_FEATURE(kAllowSubframeLocalWebApprovals);
 BASE_DECLARE_FEATURE(kAllowSubframeLocalWebApprovals);
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs;
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Uses supervised user strings on the signout dialog.
 BASE_DECLARE_FEATURE(kEnableSupervisedUserVersionSignOutDialog);
 #endif
