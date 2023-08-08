--- third_party/blink/renderer/modules/webgpu/gpu_queue.cc.orig	2023-02-01 18:43:26 UTC
+++ third_party/blink/renderer/modules/webgpu/gpu_queue.cc
@@ -699,7 +699,7 @@ bool GPUQueue::CopyFromCanvasSourceImage(
 // TODO(crbug.com/1309194): GPU-GPU copy on linux platform requires interop
 // supported. According to the bug, this change will be a long time task.
 // So disable GPU-GPU copy path on linux platform.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   unaccelerated_image = image->MakeUnaccelerated();
   image = unaccelerated_image.get();
 #endif  // BUILDFLAG(IS_LINUX)
