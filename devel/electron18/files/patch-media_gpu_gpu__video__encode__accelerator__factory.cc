--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2022-05-19 05:17:44 UTC
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -92,7 +92,7 @@ std::vector<VEAFactoryFunction> GetVEAFactoryFunctions
     return vea_factory_functions;
 
 #if BUILDFLAG(USE_VAAPI)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kVaapiVideoEncodeLinux))
     vea_factory_functions.push_back(base::BindRepeating(&CreateVaapiVEA));
 #else
