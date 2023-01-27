--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2022-11-30 08:12:58 UTC
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -337,7 +337,7 @@ class PolicyTestCase {
     const std::string os("chromeos_lacros");
 #elif BUILDFLAG(IS_IOS)
     const std::string os("ios");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const std::string os("linux");
 #elif BUILDFLAG(IS_MAC)
     const std::string os("mac");
