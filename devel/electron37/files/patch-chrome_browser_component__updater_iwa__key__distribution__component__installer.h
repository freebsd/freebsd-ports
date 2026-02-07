--- chrome/browser/component_updater/iwa_key_distribution_component_installer.h.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.h
@@ -27,7 +27,7 @@ namespace component_updater {
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIwaKeyDistributionComponent);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
