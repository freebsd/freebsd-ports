$FreeBSD$

--- src/output/ao_plugin.c.orig	2011-02-05 21:03:39.032765668 +0000
+++ src/output/ao_plugin.c	2011-02-05 21:04:11.006777588 +0000
@@ -188,6 +188,7 @@
 		break;
 	}
 
+	memset(&format, 0, sizeof(format));
 	format.rate = audio_format->sample_rate;
 	format.byte_format = AO_FMT_NATIVE;
 	format.channels = audio_format->channels;
