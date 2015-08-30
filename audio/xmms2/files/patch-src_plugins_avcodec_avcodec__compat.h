--- src/plugins/avcodec/avcodec_compat.h.orig	2011-10-20 19:26:08 UTC
+++ src/plugins/avcodec/avcodec_compat.h
@@ -1,7 +1,7 @@
 /** @file avcodec_compat.h
  *  Compatibility header for libavcodec backwards compatibility
  *
- *  Copyright (C) 2011 XMMS2 Team
+ *  Copyright (C) 2011-2014 XMMS2 Team
  *
  *  This library is free software; you can redistribute it and/or
  *  modify it under the terms of the GNU Lesser General Public
@@ -21,47 +21,16 @@
 # include "avcodec.h"
 #endif
 
-/* Map avcodec_decode_audio2 into the deprecated version
- * avcodec_decode_audio in versions earlier than 51.28 */
-#if LIBAVCODEC_VERSION_INT < 0x331c00
-# define avcodec_decode_audio2 avcodec_decode_audio
-#endif
-
-/* Handle API change that happened in libavcodec 52.00 */
-#if LIBAVCODEC_VERSION_INT < 0x340000
-# define CONTEXT_BPS(codecctx) (codecctx)->bits_per_sample
-#else
-# define CONTEXT_BPS(codecctx) (codecctx)->bits_per_coded_sample
-#endif
-
-/* Before 52.23 AVPacket was defined in avformat.h which we
- * do not want to depend on, so we define part of it manually
- * on versions smaller than 52.23 (this makes me cry) */
-#if LIBAVCODEC_VERSION_INT < 0x341700
-typedef struct AVPacket {
-        uint8_t *data;
-        int size;
-} AVPacket;
-#endif
-
-/* Same thing as above for av_init_packet and version 52.25 */
-#if LIBAVCODEC_VERSION_INT < 0x341900
-# define av_init_packet(pkt) do { \
-    (pkt)->data = NULL; \
-    (pkt)->size = 0; \
-  } while(0)
-#endif
-
-/* Map avcodec_decode_audio3 into the deprecated version
- * avcodec_decode_audio2 in versions earlier than 52.26 */
-#if LIBAVCODEC_VERSION_INT < 0x341a00
-# define avcodec_decode_audio3(avctx, samples, frame_size_ptr, avpkt) \
-    avcodec_decode_audio2(avctx, samples, frame_size_ptr, \
-                          (avpkt)->data, (avpkt)->size)
+/* Map avcodec_free_frame to av_freep if the former doesn't exist.
+ * (This is in versions earlier than 54.28.0 (libav) or 54.59.100 (ffmpeg)) */
+#if ! HAVE_AVCODEC_FREE_FRAME
+# define avcodec_free_frame av_freep
 #endif
 
-/* Handle API change that happened in libavcodec 52.64 */
-#if LIBAVCODEC_VERSION_INT < 0x344000
-# define AVMEDIA_TYPE_AUDIO CODEC_TYPE_AUDIO
+/* Map av_frame_alloc, av_frame_unref, av_frame_free into their
+ * deprecated versions in versions earlier than 55.28.1 */
+#if LIBAVCODEC_VERSION_INT < 0x371c01
+# define av_frame_alloc avcodec_alloc_frame
+# define av_frame_unref avcodec_get_frame_defaults
+# define av_frame_free avcodec_free_frame
 #endif
-
