--- components/policy/core/browser/policy_pref_mapping_test.cc.orig	2023-03-30 00:33:48 UTC
+++ components/policy/core/browser/policy_pref_mapping_test.cc
@@ -326,7 +326,7 @@ class PolicyTestCase {
     const std::string os("chromeos_lacros");
 #elif BUILDFLAG(IS_IOS)
     const std::string os("ios");
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     const std::string os("linux");
 #elif BUILDFLAG(IS_MAC)
     const std::string os("mac");
