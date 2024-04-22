--- components/supervised_user/core/common/features.cc.orig	2024-02-21 00:20:43 UTC
+++ components/supervised_user/core/common/features.cc
@@ -66,7 +66,7 @@ BASE_FEATURE(kFilterWebsitesForSupervisedUsersOnDeskto
 BASE_FEATURE(kFilterWebsitesForSupervisedUsersOnDesktopAndIOS,
              "FilterWebsitesForSupervisedUsersOnDesktopAndIOS",
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -74,7 +74,7 @@ BASE_FEATURE(kSupervisedPrefsControlledBySupervisedSto
 
 BASE_FEATURE(kSupervisedPrefsControlledBySupervisedStore,
              "SupervisedPrefsControlledBySupervisedStore",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -84,13 +84,13 @@ BASE_FEATURE(kEnableManagedByParentUi,
 // users in various UI surfaces.
 BASE_FEATURE(kEnableManagedByParentUi,
              "EnableManagedByParentUi",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -111,7 +111,7 @@ BASE_FEATURE(kClearingCookiesKeepsSupervisedUsersSigne
 // their google account when cookies are cleared
 BASE_FEATURE(kClearingCookiesKeepsSupervisedUsersSignedIn,
              "ClearingCookiesKeepsSupervisedUsersSignedIn",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -152,7 +152,7 @@ bool IsChildAccountSupervisionEnabled() {
   return base::FeatureList::IsEnabled(
              supervised_user::
                  kFilterWebsitesForSupervisedUsersOnDesktopAndIOS) ||
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
          base::FeatureList::IsEnabled(
              supervised_user::
                  kEnableExtensionsPermissionsForSupervisedUsersOnDesktop) ||
