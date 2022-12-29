--- content/browser/gpu/gpu_process_host.cc.orig	2022-07-22 17:30:31 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -101,7 +101,7 @@
 #include "ui/ozone/public/ozone_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/gfx/switches.h"
 #endif
 
@@ -253,6 +253,7 @@ static const char* const kSwitchNames[] = {
     switches::kEnableBackgroundThreadPool,
     switches::kEnableGpuRasterization,
     switches::kEnableLogging,
+    switches::kDisableUnveil,
     switches::kEnableDeJelly,
     switches::kDeJellyScreenWidth,
     switches::kDoubleBufferCompositing,
@@ -286,7 +287,7 @@ static const char* const kSwitchNames[] = {
     switches::kOzoneDumpFile,
     switches::kDisableBufferBWCompression,
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switches::kX11Display,
     switches::kNoXshm,
 #endif
