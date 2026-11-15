--- gpu/config/gpu_test_config.cc.orig	2025-04-22 20:15:27 UTC
+++ gpu/config/gpu_test_config.cc
@@ -27,7 +27,7 @@ GPUTestConfig::OS GetCurrentOS() {
 GPUTestConfig::OS GetCurrentOS() {
 #if BUILDFLAG(IS_CHROMEOS)
   return GPUTestConfig::kOsChromeOS;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GPUTestConfig::kOsLinux;
 #elif BUILDFLAG(IS_WIN)
   int32_t major_version = 0;
