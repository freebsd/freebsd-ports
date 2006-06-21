--- ./src/client/snd_dma.c.orig	Fri Jun  9 16:42:59 2006
+++ ./src/client/snd_dma.c	Sun Jun 11 15:08:02 2006
@@ -149,7 +149,7 @@
 		    snddriver = Cvar_Get("snd_driver", "oss", CVAR_ARCHIVE);
 
 		    /* Com_Printf("Loading %s sound output driver", snddriver->string); */
-		    snprintf(fn, MAX_OSPATH, "./snd_%s.so", snddriver->string);
+		    snprintf(fn, MAX_OSPATH, LIBDIR "/snd_%s.so", snddriver->string);
 		    if (stat(fn, &st) == -1) {
 		    	Com_Printf("\nload %s failed: %s\n", fn, strerror(errno));
 			return;
