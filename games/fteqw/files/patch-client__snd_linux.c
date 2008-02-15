--- ./client/snd_linux.c.orig	2008-02-15 14:04:33.000000000 -0300
+++ ./client/snd_linux.c	2008-02-15 14:09:16.000000000 -0300
@@ -114,14 +114,6 @@
 		return 0;
 	}
 
-	if (ioctl(sc->audio_fd, SNDCTL_DSP_GETOSPACE, &info)==-1)
-	{
-		perror("GETOSPACE");
-		Con_Printf(CON_ERROR "OSS: Um, can't do GETOSPACE?\n");
-		OSS_Shutdown(sc);
-		return 0;
-	}
-
 // set sample bits & speed
 
 	ioctl(sc->audio_fd, SNDCTL_DSP_GETFMTS, &fmt);
@@ -149,26 +141,6 @@
 		sc->sn.speed = tryrates[i];
 	}
 
-	if (sc->sn.samples > (info.fragstotal * info.fragsize * 4))
-	{
-		Con_Printf(CON_NOTICE "OSS: Enabling bigfoot's mmap hack! Hope you know what you're doing!\n");
-		sc->sn.samples = info.fragstotal * info.fragsize * 4;
-	}
-	sc->sn.samples = info.fragstotal * info.fragsize;
-
-// memory map the dma buffer
-
-	sc->sn.buffer = (unsigned char *) mmap(NULL, sc->sn.samples, PROT_WRITE, MAP_FILE|MAP_SHARED, sc->audio_fd, 0);
-	if (!sc->sn.buffer)
-	{
-		perror(snddev);
-		Con_Printf(CON_ERROR "OSS: Could not mmap %s\n", snddev);
-		OSS_Shutdown(sc);
-		return 0;
-	}
-
-	sc->sn.samples /= (sc->sn.samplebits/8);
-
 	tmp = 0;
 	if (sc->sn.numchannels == 2)
 		tmp = 1;
@@ -226,6 +198,35 @@
 		return 0;
 	}
 
+	if (ioctl(sc->audio_fd, SNDCTL_DSP_GETOSPACE, &info)==-1)
+	{
+		perror("GETOSPACE");
+		Con_Printf(CON_ERROR "OSS: Um, can't do GETOSPACE?\n");
+		OSS_Shutdown(sc);
+		return 0;
+	}
+
+	sc->sn.samples = info.fragstotal * info.fragsize;
+
+// memory map the dma buffer
+
+	sc->sn.buffer = (unsigned char *) mmap(NULL, sc->sn.samples, PROT_WRITE, MAP_FILE|MAP_SHARED, sc->audio_fd, 0);
+	if (!sc->sn.buffer)
+	{
+		perror(snddev);
+		Con_Printf(CON_ERROR "OSS: Could not mmap %s\n", snddev);
+		OSS_Shutdown(sc);
+		return 0;
+	}
+
+	sc->sn.samples /= (sc->sn.samplebits/8);
+
+	if (sc->sn.samples > (info.fragstotal * info.fragsize * 4))
+	{
+		Con_Printf(CON_NOTICE "OSS: Enabling bigfoot's mmap hack! Hope you know what you're doing!\n");
+		sc->sn.samples = info.fragstotal * info.fragsize * 4;
+	}
+
 // toggle the trigger & start her up
 
 	tmp = 0;
