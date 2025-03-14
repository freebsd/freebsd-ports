--- components/policy/core/common/policy_paths.cc.orig	2024-02-21 00:20:42 UTC
+++ components/policy/core/common/policy_paths.cc
@@ -17,6 +17,8 @@ const char kPolicyPath[] = "/etc/opt/chrome_for_testin
 const char kPolicyPath[] = "/etc/opt/chrome/policies";
 #elif BUILDFLAG(GOOGLE_CHROME_FOR_TESTING_BRANDING)
 const char kPolicyPath[] = "/etc/opt/chrome_for_testing/policies";
+#elif BUILDFLAG(IS_FREEBSD)
+const char kPolicyPath[] = "/usr/local/etc/chromium/policies";
 #else
 const char kPolicyPath[] = "/etc/chromium/policies";
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
