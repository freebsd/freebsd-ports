--- components/variations/service/google_groups_updater_service.cc.orig	2023-10-19 19:58:21 UTC
+++ components/variations/service/google_groups_updater_service.cc
@@ -15,7 +15,7 @@
 // information from per-profile data to local-state.
 BASE_FEATURE(kVariationsGoogleGroupFiltering,
              "VariationsGoogleGroupFiltering",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              // TODO(b/286365351): launch on Android, iOS and ChromeOS.
