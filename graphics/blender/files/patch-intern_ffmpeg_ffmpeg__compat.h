--- intern/ffmpeg/ffmpeg_compat.h.orig	2024-08-18 04:14:52 UTC
+++ intern/ffmpeg/ffmpeg_compat.h
@@ -141,6 +141,15 @@ int64_t av_get_frame_duration_in_pts_units(const AVFra
 #endif
 }
 
+FFMPEG_INLINE
+bool av_get_cur_key_frame_pts(const AVFrame *picture) {
+#if LIBAVUTIL_VERSION_INT >= AV_VERSION_INT(58, 29, 100)
+  return (picture->flags & AV_FRAME_FLAG_KEY);
+#else
+  return (picture->key_frame);
+#endif
+}
+
 /* -------------------------------------------------------------------- */
 /** \name Deinterlace code block
  *
