https://github.com/cmus/cmus/commit/b595b8cd7fee

--- ip/ffmpeg.c.orig	2016-11-20 12:29:46 UTC
+++ ip/ffmpeg.c
@@ -252,8 +252,8 @@ static int ffmpeg_open(struct input_plugin_data *ip_da
 			break;
 		}
 
-		if (codec->capabilities & CODEC_CAP_TRUNCATED)
-			cc->flags |= CODEC_FLAG_TRUNCATED;
+		if (codec->capabilities & AV_CODEC_CAP_TRUNCATED)
+			cc->flags |= AV_CODEC_FLAG_TRUNCATED;
 
 #if (LIBAVCODEC_VERSION_INT < ((53<<16)+(8<<8)+0))
 		if (avcodec_open(cc, codec) < 0) {
