--- ui/base/resource/resource_bundle.cc.orig	2021-04-14 01:09:39 UTC
+++ ui/base/resource/resource_bundle.cc
@@ -821,7 +821,7 @@ void ResourceBundle::ReloadFonts() {
 }
 
 ScaleFactor ResourceBundle::GetMaxScaleFactor() const {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return max_scale_factor_;
 #else
   return GetSupportedScaleFactors().back();
@@ -874,7 +874,7 @@ void ResourceBundle::InitSharedInstance(Delegate* dele
   // On platforms other than iOS, 100P is always a supported scale factor.
   // For Windows we have a separate case in this function.
   supported_scale_factors.push_back(SCALE_FACTOR_100P);
-#if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
+#if defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD) || \
     defined(OS_WIN)
   supported_scale_factors.push_back(SCALE_FACTOR_200P);
 #endif
