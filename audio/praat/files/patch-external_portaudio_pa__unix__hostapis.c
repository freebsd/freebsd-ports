--- external/portaudio/pa_unix_hostapis.c.orig	2019-11-26 11:48:46 UTC
+++ external/portaudio/pa_unix_hostapis.c
@@ -64,6 +64,8 @@ PaUtilHostApiInitializer *paHostApiInitializers[] =
 			#elif defined (JACK)
 				PaJack_Initialize,
 			#endif
+		#else
+			PaOSS_Initialize,
 		#endif
         0   /* NULL terminated array */
     };
