--- external/portaudio/pa_unix_hostapis.c.orig	2015-05-20 01:47:31 UTC
+++ external/portaudio/pa_unix_hostapis.c
@@ -60,6 +60,8 @@ PaUtilHostApiInitializer *paHostApiIniti
     {
 		#if defined (linux) && defined (ALSA)
 			PaAlsa_Initialize,   // ppgb
+		#else
+			PaOSS_Initialize,
 		#endif
         0   /* NULL terminated array */
     };
