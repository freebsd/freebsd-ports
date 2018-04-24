ffmpeg.c:996:34: error: use of undeclared identifier 'CODEC_CAP_TRUNCATED'
        if (data->codec->capabilities & CODEC_CAP_TRUNCATED)
                                        ^
ffmpeg.c:997:23: error: use of undeclared identifier 'CODEC_FLAG_TRUNCATED'
                data->enc->flags |= CODEC_FLAG_TRUNCATED;
                                    ^
ffmpeg.c:1028:34: error: use of undeclared identifier 'CODEC_CAP_DELAY'
        if (data->codec->capabilities & CODEC_CAP_DELAY)
                                        ^

--- decoder_plugins/ffmpeg/ffmpeg.c.orig	2016-11-16 00:54:37 UTC
+++ decoder_plugins/ffmpeg/ffmpeg.c
@@ -993,8 +993,8 @@ static void *ffmpeg_open (const char *file)
 #endif
 
 	set_downmixing (data);
-	if (data->codec->capabilities & CODEC_CAP_TRUNCATED)
-		data->enc->flags |= CODEC_FLAG_TRUNCATED;
+	if (data->codec->capabilities & AV_CODEC_CAP_TRUNCATED)
+		data->enc->flags |= AV_CODEC_FLAG_TRUNCATED;
 
 #ifdef HAVE_AVCODEC_OPEN2
 	if (avcodec_open2 (data->enc, data->codec, NULL) < 0)
@@ -1025,7 +1025,7 @@ static void *ffmpeg_open (const char *file)
 
 	data->sample_width = sfmt_Bps (data->fmt);
 
-	if (data->codec->capabilities & CODEC_CAP_DELAY)
+	if (data->codec->capabilities & AV_CODEC_CAP_DELAY)
 		data->delay = true;
 	data->seek_broken = is_seek_broken (data);
 	data->timing_broken = is_timing_broken (data->ic);
