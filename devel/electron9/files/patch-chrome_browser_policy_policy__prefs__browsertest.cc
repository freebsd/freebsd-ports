--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2020-05-26 08:03:18 UTC
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -296,6 +296,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
