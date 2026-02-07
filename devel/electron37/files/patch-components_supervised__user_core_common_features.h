--- components/supervised_user/core/common/features.h.orig	2025-06-30 07:04:30 UTC
+++ components/supervised_user/core/common/features.h
@@ -20,12 +20,12 @@ BASE_DECLARE_FEATURE(kAllowSubframeLocalWebApprovals);
 BASE_DECLARE_FEATURE(kAllowSubframeLocalWebApprovals);
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs;
 #endif  // BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Whether we show an error screen in case of failure of a local web approval.
 BASE_DECLARE_FEATURE(kEnableLocalWebApprovalErrorDialog);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
@@ -37,7 +37,7 @@ BASE_DECLARE_FEATURE(kSupervisedUserBlockInterstitialV
 // Whether supervised users see an updated URL filter interstitial.
 BASE_DECLARE_FEATURE(kSupervisedUserBlockInterstitialV3);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Enable different web sign in interception behaviour for supervised users:
 //
 // 1. Supervised user signs in to existing signed out Profile: show modal
@@ -55,7 +55,7 @@ BASE_DECLARE_FEATURE(kForceSafeSearchForUnauthenticate
 // unauthenticated (e.g. signed out of the content area) account.
 BASE_DECLARE_FEATURE(kForceSafeSearchForUnauthenticatedSupervisedUsers);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Uses supervised user strings on the signout dialog.
 BASE_DECLARE_FEATURE(kEnableSupervisedUserVersionSignOutDialog);
 #endif
