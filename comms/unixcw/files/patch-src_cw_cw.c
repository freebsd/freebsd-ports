--- src/cw/cw.c.orig	2018-08-08 04:24:25 UTC
+++ src/cw/cw.c
@@ -598,7 +598,9 @@ int main (int argc, char *const argv[])
 		}
 	}
 
+#ifndef __FreeBSD__
 	if (config->audio_system == CW_AUDIO_ALSA
+	    ) {
 	    && cw_is_pa_possible(NULL)) {
 
 		fprintf(stdout, "Selected audio system is ALSA, but audio on your system is handled by PulseAudio. Expect problems with timing.\n");
@@ -607,6 +609,7 @@ int main (int argc, char *const argv[])
 		fprintf(stdout, "Press Enter key to continue\n");
 		getchar();
 	}
+#endif
 
 	generator = cw_generator_new_from_config(config);
 	if (!generator) {
