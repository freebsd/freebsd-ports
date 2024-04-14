--- content/browser/gpu/gpu_process_host.cc.orig	2024-02-21 00:20:44 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -256,6 +256,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableGpuRasterization,
     switches::kEnableSkiaGraphite,
     switches::kEnableLogging,
+    switches::kDisableUnveil,
     switches::kDoubleBufferCompositing,
     switches::kHeadless,
     switches::kLoggingLevel,
@@ -290,7 +291,7 @@ static const char* const kSwitchNames[] = {
     switches::kDisableExplicitDmaFences,
     switches::kOzoneDumpFile,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
