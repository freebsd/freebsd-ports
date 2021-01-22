--- components/url_formatter/spoof_checks/idn_spoof_checker.cc.orig	2020-05-26 08:03:22 UTC
+++ components/url_formatter/spoof_checks/idn_spoof_checker.cc
@@ -271,7 +271,7 @@ IDNSpoofChecker::IDNSpoofChecker() {
   // The ideal fix would be to change the omnibox font used for Thai. In
   // that case, the Linux-only list should be revisited and potentially
   // removed.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
        "[ทนบพรหเแ๐ดลปฟม]",
 #else
        "[บพเแ๐]",
