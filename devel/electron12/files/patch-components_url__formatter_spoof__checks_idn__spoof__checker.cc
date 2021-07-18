--- components/url_formatter/spoof_checks/idn_spoof_checker.cc.orig	2021-04-14 01:08:47 UTC
+++ components/url_formatter/spoof_checks/idn_spoof_checker.cc
@@ -292,7 +292,7 @@ IDNSpoofChecker::IDNSpoofChecker() {
   // The ideal fix would be to change the omnibox font used for Thai. In
   // that case, the Linux-only list should be revisited and potentially
   // removed.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
        "[ทนบพรหเแ๐ดลปฟม]",
 #else
        "[บพเแ๐]",
