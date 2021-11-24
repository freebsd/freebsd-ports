--- components/feature_engagement/public/feature_configurations.cc.orig	2021-07-15 19:13:37 UTC
+++ components/feature_engagement/public/feature_configurations.cc
@@ -12,7 +12,7 @@ namespace feature_engagement {
 
 base::Optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   if (kIPHPasswordsAccountStorageFeature.name == feature->name) {
     base::Optional<FeatureConfig> config = FeatureConfig();
@@ -41,7 +41,7 @@ base::Optional<FeatureConfig> GetClientSideFeatureConf
         EventConfig("profile_menu_shown", Comparator(EQUAL, 0), 360, 360);
     return config;
   }
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if defined(OS_ANDROID)
