--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2025-06-30 07:04:30 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -82,7 +82,7 @@ using media_gpu_vaapi::kModuleVa_prot;
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
