--- media/gpu/vaapi/vaapi_wrapper.cc.orig	2026-03-13 16:54:03 UTC
+++ media/gpu/vaapi/vaapi_wrapper.cc
@@ -79,7 +79,7 @@ using media_gpu_vaapi::kModuleVa_prot;
 using media_gpu_vaapi::kModuleVa_prot;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_split.h"
 #endif
 
