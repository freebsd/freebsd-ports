--- components/url_formatter/spoof_checks/idn_spoof_checker.cc.orig	2023-03-30 00:33:50 UTC
+++ components/url_formatter/spoof_checks/idn_spoof_checker.cc
@@ -292,7 +292,7 @@ IDNSpoofChecker::IDNSpoofChecker() {
   // The ideal fix would be to change the omnibox font used for Thai. In
   // that case, the Linux-only list should be revisited and potentially
   // removed.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
        "[ทนบพรหเแ๐ดลปฟม]",
 #else
        "[บพเแ๐]",
