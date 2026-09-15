-- Fix build against FFmpeg 9.x where AVCodec.pix_fmts was removed.
-- The pixel-format check for CUDA/VAAPI encoders is only available before
-- libavcodec 63, so guard the block with a version macro.

--- opencv/modules/videoio/src/cap_ffmpeg_hw.hpp.orig	2025-07-04 16:37:46 UTC
+++ opencv/modules/videoio/src/cap_ffmpeg_hw.hpp
@@ -757,6 +757,7 @@
 #endif
             if (hw_type == AV_HWDEVICE_TYPE_CUDA) // CUDA encoders don't support avcodec_get_hw_config()
                 hw_native_fmt = AV_PIX_FMT_CUDA;
+#if LIBAVCODEC_VERSION_MAJOR < 63
             if (av_codec_is_encoder(c) && hw_native_fmt != AV_PIX_FMT_NONE && c->pix_fmts) {
                 for (int i = 0; c->pix_fmts[i] != AV_PIX_FMT_NONE; i++) {
                     if (c->pix_fmts[i] == hw_native_fmt) {
@@ -766,6 +767,7 @@
                     }
                 }
             }
+#endif
             for (int i = 0;; i++) {
                 const AVCodecHWConfig *hw_config = avcodec_get_hw_config(c, i);
                 if (!hw_config)
