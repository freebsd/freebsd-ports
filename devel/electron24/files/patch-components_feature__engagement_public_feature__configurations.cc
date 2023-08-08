--- components/feature_engagement/public/feature_configurations.cc.orig	2023-03-30 00:33:48 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -39,7 +39,7 @@ FeatureConfig CreateAlwaysTriggerConfig(const base::Fe
 absl::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (kIPHPasswordsAccountStorageFeature.name == feature->name) {
     absl::optional<FeatureConfig> config = FeatureConfig();
     config->valid = true;
@@ -1070,7 +1070,8 @@ absl::optional<FeatureConfig> GetClientSideFeatureConf
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
   if (kIPHAutofillVirtualCardSuggestionFeature.name == feature->name) {
     // A config that allows the virtual card credit card suggestion IPH to be
     // shown when:
