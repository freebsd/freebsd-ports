--- content/browser/gpu/gpu_process_host.cc.orig	2026-08-19 23:17:14 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -284,6 +284,7 @@ static const char* const kSwitchNames[] = {
     switches::kDisableSkiaGraphite,
     switches::kDisableSkiaGraphitePrecompilation,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -308,7 +309,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableNativeGpuMemoryBuffers,
     switches::kRenderNodeOverride,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
