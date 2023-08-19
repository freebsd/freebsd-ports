From 941fab9023f0af19f178771effd2a73865e849ba Mon Sep 17 00:00:00 2001
From: ejurgensen <espenjurgensen@gmail.com>
Date: Thu, 17 Aug 2023 23:09:41 +0200
Subject: [PATCH] [xcode] Circumvent ffmpeg 6 ALAC encoding problem

The default ffmpeg ALAC encoder, "alac", requires fixed frames of size 4096,
but the Airplay 2 implementation feeds it with frames of size 352. Before
ffmpeg 6 this worked, but not any more. Seems a frame size check has been
added.

This commit doesn't fix this, but circumvents the ffmpeg error by modifying the
frame size that ffmpeg checks.

Fixes issue #1640

--- src/transcode.c.orig	2022-01-29 16:41:27 UTC
+++ src/transcode.c
@@ -42,6 +42,8 @@
 #include "misc.h"
 #include "transcode.h"
 
+#define USE_ALAC_FRAME_SIZE_HACK (LIBAVCODEC_VERSION_MAJOR > 59) || ((LIBAVCODEC_VERSION_MAJOR == 59) && (LIBAVCODEC_VERSION_MINOR > 31))
+
 // Interval between ICY metadata checks for streams, in seconds
 #define METADATA_ICY_INTERVAL 5
 // Maximum number of streams in a file that we will accept
@@ -506,6 +508,16 @@ stream_add(struct encode_ctx *ctx, struct stream_ctx *
       avcodec_free_context(&s->codec);
       return -1;
     }
+
+  // airplay.c "misuses" the ffmpeg alac encoder in that it pushes frames with
+  // 352 samples even though the encoder wants 4096 (and doesn't have variable
+  // frame capability). This worked with no issues until ffmpeg 6, where it
+  // seems a frame size check was added. The below circumvents the check, but is
+  // dirty because we shouldn't be writing to this data element.
+#if USE_ALAC_FRAME_SIZE_HACK
+  if (codec_id == AV_CODEC_ID_ALAC)
+    s->codec->frame_size = 352;
+#endif
 
   // Copy the codec parameters we just set to the stream, so the muxer knows them
   ret = avcodec_parameters_from_context(s->stream->codecpar, s->codec);
