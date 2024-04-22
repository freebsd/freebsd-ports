--- jack/pcm_jack.c.orig	2023-11-03 22:31:39 UTC
+++ jack/pcm_jack.c
@@ -603,7 +603,7 @@ static int snd_pcm_jack_open(snd_pcm_t **pcmp, const c
 	}
 
 	if (client_name == NULL) {
-		const char *pname = program_invocation_short_name;
+		const char *pname = getprogname();
 		if (!pname[0]) {
 			pname = "alsa-jack";
 		}
