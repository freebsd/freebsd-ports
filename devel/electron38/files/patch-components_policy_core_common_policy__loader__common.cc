--- components/policy/core/common/policy_loader_common.cc.orig	2025-08-26 20:49:50 UTC
+++ components/policy/core/common/policy_loader_common.cc
@@ -46,7 +46,7 @@ const char* kSensitivePolicies[] = {
     key::kDefaultSearchProviderEnabled,
     key::kSafeBrowsingEnabled,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     key::kAutoOpenFileTypes,
     key::kEnterpriseSearchAggregatorSettings,
     key::kHomepageIsNewTabPage,
@@ -57,7 +57,7 @@ const char* kSensitivePolicies[] = {
     key::kSafeBrowsingAllowlistDomains,
     key::kSiteSearchSettings,
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     key::kCommandLineFlagSecurityWarningsEnabled,
     key::kEnterpriseCustomLabelForBrowser,
     key::kEnterpriseLogoUrlForBrowser,
