--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2026-06-23 23:37:18 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -83,7 +83,7 @@ using media_gpu_vaapi::kModuleVa_prot;
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_split.h"
 #endif
 
