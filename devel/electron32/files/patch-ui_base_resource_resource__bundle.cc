--- ui/base/resource/resource_bundle.cc.orig	2024-02-21 00:21:15 UTC
+++ ui/base/resource/resource_bundle.cc
@@ -926,7 +926,7 @@ ResourceScaleFactor ResourceBundle::GetMaxResourceScal
 }
 
 ResourceScaleFactor ResourceBundle::GetMaxResourceScaleFactor() const {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return max_scale_factor_;
 #else
   return GetMaxSupportedResourceScaleFactor();
