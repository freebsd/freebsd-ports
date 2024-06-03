--- content/browser/gpu/gpu_process_host.cc.orig	2024-04-15 20:33:57 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -264,6 +264,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableLowEndDeviceMode,
     switches::kDisableSkiaGraphite,
     switches::kDisableLowEndDeviceMode,
+    switches::kDisableUnveil,
     switches::kProfilingAtStart,
     switches::kProfilingFile,
     switches::kProfilingFlush,
@@ -290,7 +291,7 @@ static const char* const kSwitchNames[] = {
     switches::kDisableExplicitDmaFences,
     switches::kOzoneDumpFile,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
