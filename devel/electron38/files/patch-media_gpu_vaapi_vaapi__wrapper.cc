--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2025-08-26 20:49:50 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -83,7 +83,7 @@ using media_gpu_vaapi::kModuleVa_prot;
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/files/file_util.h"
 #include "base/strings/string_split.h"
 #endif
