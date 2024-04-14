--- media/base/libvpx_thread_wrapper.cc.orig	2024-02-21 00:20:48 UTC
+++ media/base/libvpx_thread_wrapper.cc
@@ -5,17 +5,21 @@
 #include "media/base/libvpx_thread_wrapper.h"
 
 #include "media/base/codec_worker_impl.h"
+#if !BUILDFLAG(IS_BSD)
 #include "third_party/libvpx/source/libvpx/vpx_util/vpx_thread.h"
+#endif
 
 namespace media {
 
 void InitLibVpxThreadWrapper() {
+#if !BUILDFLAG(IS_BSD)
   const VPxWorkerInterface interface =
       CodecWorkerImpl<VPxWorkerInterface, VPxWorkerImpl, VPxWorker,
                       VPxWorkerStatus, NOT_OK, OK,
                       WORK>::GetCodecWorkerInterface();
 
   CHECK(vpx_set_worker_interface(&interface));
+#endif
 }
 
 }  // namespace media
