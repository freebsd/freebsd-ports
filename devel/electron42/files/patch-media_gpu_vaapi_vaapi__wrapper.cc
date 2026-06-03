--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2026-04-28 21:06:17 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -80,7 +80,7 @@ using media_gpu_vaapi::kModuleVa_prot;
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_split.h"
 #endif
 
