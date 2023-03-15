--- ip/ffmpeg.c.orig	2022-07-05 20:20:28 UTC
+++ ip/ffmpeg.c
@@ -202,9 +202,6 @@ static int ffmpeg_open(struct input_plugin_data *ip_da
 			break;
 		}
 
-		if (codec->capabilities & AV_CODEC_CAP_TRUNCATED)
-			cc->flags |= AV_CODEC_FLAG_TRUNCATED;
-
 		if (avcodec_open2(cc, codec, NULL) < 0) {
 			d_print("could not open codec: %d, %s\n", cc->codec_id, avcodec_get_name(cc->codec_id));
 			err = -IP_ERROR_UNSUPPORTED_FILE_TYPE;
