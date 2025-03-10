--- jack/pcm_jack.c.orig	2024-06-10 09:18:39 UTC
+++ jack/pcm_jack.c
@@ -602,7 +602,7 @@ static int snd_pcm_jack_open(snd_pcm_t **pcmp, const c
 	}
 
 	if (client_name == NULL) {
-#if defined(_GNU_SOURCE)
+#if defined(_GNU_SOURCE) && defined(__linux__)
 		const char *pname = program_invocation_short_name;
 #else
 		const char *pname = getprogname();
