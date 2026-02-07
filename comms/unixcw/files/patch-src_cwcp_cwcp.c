--- src/cwcp/cwcp.c.orig	2018-08-08 04:24:32 UTC
+++ src/cwcp/cwcp.c
@@ -1732,6 +1732,7 @@ int main(int argc, char **argv)
 		}
 	}
 
+#ifndef __FreeBSD__
 	if (config->audio_system == CW_AUDIO_ALSA
 	    && cw_is_pa_possible(NULL)) {
 
@@ -1741,6 +1742,7 @@ int main(int argc, char **argv)
 		fprintf(stdout, "Press Enter key to continue\n");
 		getchar();
 	}
+#endif
 
 	generator = cw_generator_new_from_config(config);
 	if (!generator) {
