--- components/supervised_user/core/common/pref_names.h.orig	2025-06-30 07:04:30 UTC
+++ components/supervised_user/core/common/pref_names.h
@@ -129,7 +129,7 @@ inline constexpr char kDefaultSupervisedUserFilteringB
     "profile.managed.default_filtering_behavior";
 
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // An integer pref that stores the current state of the local extension
 // parent approval migration when the feature
 // `kEnableSupervisedUserSkipParentApprovalToInstallExtensions` becomes enabled.
