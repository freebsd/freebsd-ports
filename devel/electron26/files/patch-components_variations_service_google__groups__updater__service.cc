--- components/variations/service/google_groups_updater_service.cc.orig	2023-08-10 01:48:42 UTC
+++ components/variations/service/google_groups_updater_service.cc
@@ -29,7 +29,7 @@ const char kDogfoodGroupsSyncPrefGaiaIdKey[] = "gaia_i
 // information from per-profile data to local-state.
 BASE_FEATURE(kVariationsGoogleGroupFiltering,
              "VariationsGoogleGroupFiltering",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              // TODO(b/286365351): launch on Android, iOS and ChromeOS.
