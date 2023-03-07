--- thirdparty/libvpx/vpx/vpx_frame_buffer.h.orig   2019-03-23 14:31:21 UTC
+++ thirdparty/libvpx/vpx/vpx_frame_buffer.h
@@ -8,8 +8,8 @@
  *  be found in the AUTHORS file in the root of the source tree.
  */

-#ifndef VPX_VPX_FRAME_BUFFER_H_
-#define VPX_VPX_FRAME_BUFFER_H_
+#ifndef VPX_VPX_VPX_FRAME_BUFFER_H_
+#define VPX_VPX_VPX_FRAME_BUFFER_H_

 /*!\file
  * \brief Describes the decoder external frame buffer interface.
@@ -80,4 +80,4 @@ typedef int (*vpx_release_frame_buffer_cb_fn_t)(
 }  // extern "C"
 #endif

-#endif  // VPX_VPX_FRAME_BUFFER_H_
+#endif  // VPX_VPX_VPX_FRAME_BUFFER_H_
