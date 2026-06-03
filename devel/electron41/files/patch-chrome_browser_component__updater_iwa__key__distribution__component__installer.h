--- chrome/browser/component_updater/iwa_key_distribution_component_installer.h.orig	2026-01-07 00:52:53 UTC
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.h
@@ -26,7 +26,7 @@ namespace component_updater {
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIwaKeyDistributionComponent);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
