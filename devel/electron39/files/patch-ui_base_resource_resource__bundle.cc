--- ui/base/resource/resource_bundle.cc.orig	2025-10-21 20:19:54 UTC
+++ ui/base/resource/resource_bundle.cc
@@ -998,7 +998,7 @@ ResourceScaleFactor ResourceBundle::GetMaxResourceScal
 }
 
 ResourceScaleFactor ResourceBundle::GetMaxResourceScaleFactor() const {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return max_scale_factor_;
 #else
   return GetMaxSupportedResourceScaleFactor();
