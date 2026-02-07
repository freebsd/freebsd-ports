--- media/gpu/gpu_video_encode_accelerator_factory.cc.orig	2025-04-22 20:15:27 UTC
+++ media/gpu/gpu_video_encode_accelerator_factory.cc
@@ -160,7 +160,7 @@ std::vector<VEAFactoryFunction> GetVEAFactoryFunctions
   }
 
 #if BUILDFLAG(USE_VAAPI)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     vea_factory_functions->push_back(base::BindRepeating(&CreateVaapiVEA));
   }
@@ -168,7 +168,7 @@ std::vector<VEAFactoryFunction> GetVEAFactoryFunctions
   vea_factory_functions->push_back(base::BindRepeating(&CreateVaapiVEA));
 #endif
 #elif BUILDFLAG(USE_V4L2_CODEC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(kAcceleratedVideoEncodeLinux)) {
     vea_factory_functions->push_back(base::BindRepeating(&CreateV4L2VEA));
   }
