--- ./client/snd_linux.c.orig	Tue Jul 18 00:34:50 2006
+++ ./client/snd_linux.c	Sat Sep  2 18:40:11 2006
@@ -115,14 +115,6 @@
 		return 0;
 	}
 
-	if (ioctl(sc->audio_fd, SNDCTL_DSP_GETOSPACE, &info)==-1)
-	{
-		perror("GETOSPACE");
-		Con_Printf(S_ERROR "OSS: Um, can't do GETOSPACE?\n");
-		OSS_Shutdown(sc);
-		return 0;
-	}
-
 	sc->sn.splitbuffer = 0;
 
 // set sample bits & speed
@@ -152,27 +144,6 @@
 		sc->sn.speed = tryrates[i];
 	}
 
-	if (sc->sn.samples > (info.fragstotal * info.fragsize * 4))
-	{
-		Con_Printf(S_NOTICE "OSS: Enabling bigfoot's mmap hack! Hope you know what you're doing!\n");
-		sc->sn.samples = info.fragstotal * info.fragsize * 4;
-	}
-	sc->sn.samples = info.fragstotal * info.fragsize;
-	sc->sn.submission_chunk = 1;
-
-// memory map the dma buffer
-
-	sc->sn.buffer = (unsigned char *) mmap(NULL, sc->sn.samples, PROT_WRITE, MAP_FILE|MAP_SHARED, sc->audio_fd, 0);
-	if (!sc->sn.buffer)
-	{
-		perror(snddev);
-		Con_Printf(S_ERROR "OSS: Could not mmap %s\n", snddev);
-		OSS_Shutdown(sc);
-		return 0;
-	}
-
-	sc->sn.samples /= (sc->sn.samplebits/8);
-
 	tmp = 0;
 	if (sc->sn.numchannels == 2)
 		tmp = 1;
@@ -228,6 +199,36 @@
 		Con_Printf(S_ERROR "OSS: %d-bit sound not supported.\n", sc->sn.samplebits);
 		OSS_Shutdown(sc);
 		return 0;
+	}
+
+	if (ioctl(sc->audio_fd, SNDCTL_DSP_GETOSPACE, &info)==-1)
+	{
+		perror("GETOSPACE");
+		Con_Printf(S_ERROR "OSS: Um, can't do GETOSPACE?\n");
+		OSS_Shutdown(sc);
+		return 0;
+	}
+
+	sc->sn.samples = info.fragstotal * info.fragsize;
+	sc->sn.submission_chunk = 1;
+
+// memory map the dma buffer
+
+	sc->sn.buffer = (unsigned char *) mmap(NULL, sc->sn.samples, PROT_WRITE, MAP_FILE|MAP_SHARED, sc->audio_fd, 0);
+	if (!sc->sn.buffer)
+	{
+		perror(snddev);
+		Con_Printf(S_ERROR "OSS: Could not mmap %s\n", snddev);
+		OSS_Shutdown(sc);
+		return 0;
+	}
+
+	sc->sn.samples /= (sc->sn.samplebits/8);
+
+	if (sc->sn.samples > (info.fragstotal * info.fragsize * 4))
+	{
+		Con_Printf(S_NOTICE "OSS: Enabling bigfoot's mmap hack! Hope you know what you're doing!\n");
+		sc->sn.samples = info.fragstotal * info.fragsize * 4;
 	}
 
 // toggle the trigger & start her up
