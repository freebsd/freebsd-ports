--- src/stream.c.orig	2021-02-10 23:52:27 UTC
+++ src/stream.c
@@ -225,7 +225,7 @@ _stream_cfg_stream(struct stream *s, cfg_stream_t cfg_
		break;
	case CFG_STREAM_MP3:
		if (SHOUTERR_SUCCESS !=
-		    shout_set_content_format(s->shout, SHOUT_FORMAT_MP3, 0, NULL)) {
+                    shout_set_content_format(s->shout, SHOUT_FORMAT_MP3, SHOUT_USAGE_AUDIO, NULL)) {
			log_error("stream: %s: format: %s: %s",
			    s->name, cfg_stream_get_format_str(cfg_stream),
			    shout_get_error(s->shout));
