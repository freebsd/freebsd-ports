--- content/public/common/use_zoom_for_dsf_policy.cc.orig	2020-05-26 07:48:23 UTC
+++ content/public/common/use_zoom_for_dsf_policy.cc
@@ -25,7 +25,7 @@ const base::Feature kUseZoomForDsfEnabledByDefault{
 #endif
 
 bool IsUseZoomForDSFEnabledByDefault() {
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN) || defined(OS_ANDROID)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
