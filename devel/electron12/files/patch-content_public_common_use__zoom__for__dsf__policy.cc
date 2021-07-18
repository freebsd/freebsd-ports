--- content/public/common/use_zoom_for_dsf_policy.cc.orig	2021-01-07 00:36:33 UTC
+++ content/public/common/use_zoom_for_dsf_policy.cc
@@ -25,7 +25,7 @@ const base::Feature kUseZoomForDsfEnabledByDefault{
 #endif
 
 bool IsUseZoomForDSFEnabledByDefault() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN) || defined(OS_ANDROID)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
