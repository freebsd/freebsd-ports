--- content/browser/gpu/gpu_process_host.cc.orig	2023-12-20 07:12:20 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -255,6 +255,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableGpuRasterization,
     switches::kEnableSkiaGraphite,
     switches::kEnableLogging,
+    switches::kDisableUnveil,
     switches::kDoubleBufferCompositing,
     switches::kHeadless,
     switches::kLoggingLevel,
@@ -290,7 +291,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kDisableBufferBWCompression,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
