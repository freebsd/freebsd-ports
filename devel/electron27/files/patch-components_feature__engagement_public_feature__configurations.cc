--- components/feature_engagement/public/feature_configurations.cc.orig	2023-10-19 19:58:18 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -46,7 +46,7 @@ FeatureConfig CreateAlwaysTriggerConfig(const base::Fe
 absl::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (kIPHPasswordsAccountStorageFeature.name == feature->name) {
     absl::optional<FeatureConfig> config = FeatureConfig();
     config->valid = true;
@@ -1336,7 +1336,8 @@ absl::optional<FeatureConfig> GetClientSideFeatureConf
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 
   if (kIPHAutofillExternalAccountProfileSuggestionFeature.name ==
       feature->name) {
