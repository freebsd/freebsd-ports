--- ui/base/resource/resource_bundle.cc.orig	2022-05-11 07:17:06 UTC
+++ ui/base/resource/resource_bundle.cc
@@ -849,7 +849,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ResourceScaleFactor ResourceBundle::GetMaxResourceScaleFactor() const {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedResourceScaleFactors().back();
