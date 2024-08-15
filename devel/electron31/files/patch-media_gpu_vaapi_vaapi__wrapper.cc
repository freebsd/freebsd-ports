--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2024-06-18 21:43:35 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -71,7 +71,7 @@ using media_gpu_vaapi::kModuleVa_prot;
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
