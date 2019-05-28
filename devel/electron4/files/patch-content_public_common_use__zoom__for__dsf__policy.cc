--- content/public/common/use_zoom_for_dsf_policy.cc.orig	2019-03-15 06:37:23 UTC
+++ content/public/common/use_zoom_for_dsf_policy.cc
@@ -20,7 +20,7 @@ const base::Feature kUseZoomForDsfEnabledByDefault{
 #endif
 
 bool IsUseZoomForDSFEnabledByDefault() {
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return true;
 #elif defined(OS_WIN)
   return base::FeatureList::IsEnabled(kUseZoomForDsfEnabledByDefault);
