--- chrome/browser/policy/policy_prefs_browsertest.cc.orig	2019-12-12 12:39:12 UTC
+++ chrome/browser/policy/policy_prefs_browsertest.cc
@@ -184,6 +184,8 @@ class PolicyTestCase {
     const std::string os("chromeos");
 #elif defined(OS_LINUX)
     const std::string os("linux");
+#elif defined(OS_FREEBSD)
+    const std::string os("freebsd");
 #else
 #error "Unknown platform"
 #endif
