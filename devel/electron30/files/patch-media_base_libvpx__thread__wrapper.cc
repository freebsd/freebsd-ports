--- media/base/libvpx_thread_wrapper.cc.orig	2024-04-15 20:34:00 UTC
+++ media/base/libvpx_thread_wrapper.cc
@@ -5,11 +5,14 @@
 #include "media/base/libvpx_thread_wrapper.h"
 
 #include "media/base/codec_worker_impl.h"
+#if !BUILDFLAG(IS_OPENBSD)
 #include "third_party/libvpx/source/libvpx/vpx_util/vpx_thread.h"
+#endif
 
 namespace media {
 
 void InitLibVpxThreadWrapper() {
+#if !BUILDFLAG(IS_OPENBSD)
   const VPxWorkerInterface interface =
       CodecWorkerImpl<VPxWorkerInterface, VPxWorkerImpl, VPxWorker,
                       VPxWorkerStatus, VPX_WORKER_STATUS_NOT_OK,
@@ -17,6 +20,7 @@ void InitLibVpxThreadWrapper() {
                       VPX_WORKER_STATUS_WORKING>::GetCodecWorkerInterface();
 
   CHECK(vpx_set_worker_interface(&interface));
+#endif
 }
 
 }  // namespace media
