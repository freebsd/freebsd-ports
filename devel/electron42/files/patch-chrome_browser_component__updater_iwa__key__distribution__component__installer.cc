--- chrome/browser/component_updater/iwa_key_distribution_component_installer.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/component_updater/iwa_key_distribution_component_installer.cc
@@ -73,7 +73,7 @@ bool IsComponentSupported() {
   // the main IWA feature.
 #if BUILDFLAG(IS_WIN)
   return base::FeatureList::IsEnabled(features::kIsolatedWebApps);
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       component_updater::kIwaKeyDistributionComponent);
 #else
@@ -94,7 +94,7 @@ namespace component_updater {
 
 namespace component_updater {
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIwaKeyDistributionComponent,
 #if BUILDFLAG(IS_CHROMEOS)
              base::FEATURE_ENABLED_BY_DEFAULT
