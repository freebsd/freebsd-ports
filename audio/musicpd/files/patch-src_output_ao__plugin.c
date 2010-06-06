
$FreeBSD$

--- src/output/ao_plugin.c.orig
+++ src/output/ao_plugin.c
@@ -175,6 +175,7 @@
 	if (audio_format->bits > 16)
 		audio_format->bits = 16;
 
+	memset(&format, 0, sizeof(format));
 	format.bits = audio_format->bits;
 	format.rate = audio_format->sample_rate;
 	format.byte_format = AO_FMT_NATIVE;
