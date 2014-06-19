--- audio_jack.c.orig	2011-11-26 16:01:22.000000000 -0800
+++ audio_jack.c	2014-06-02 02:37:35.000000000 -0700
@@ -93,8 +93,9 @@
 	// save some info in the SDR
 	sdr->size = jack_get_buffer_size(client);
 	sdr->sample_rate = jack_get_sample_rate(client);
-	sdr->iqSample = g_new0(complex, sdr->size);
+	sdr->iqSample = g_new0(complex double, sdr->size);
 	sdr->output = g_new0(double, sdr->size);
+	return 0;
 }
 
 int audio_stop(sdr_data_t *sdr) {
@@ -104,6 +105,7 @@
 	if (sdr->iqSample) g_free(sdr->iqSample);
 	if (sdr->output) g_free(sdr->output);
 
+	return 0;
 }
 
 int audio_connect(sdr_data_t *sdr, gboolean ci, gboolean co) {
@@ -163,6 +165,7 @@
 		}
 		free(ports);
 	}
+	return 0;
 }
 
 /* vim: set noexpandtab ai ts=4 sw=4 tw=4: */
