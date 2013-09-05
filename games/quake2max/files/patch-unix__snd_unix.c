--- unix/snd_unix.c.orig	2006-01-01 20:46:30.000000000 +0800
+++ unix/snd_unix.c	2013-09-05 13:28:24.000000000 +0800
@@ -59,7 +59,7 @@ qboolean SNDDMA_Init(void)
 	extern uid_t saved_euid;
 
 	if (snd_inited)
-		return;
+		return 1;
 
 	if (!snddevice) {
 		sndbits = Cvar_Get("sndbits", "16", CVAR_ARCHIVE);
@@ -115,7 +115,7 @@ qboolean SNDDMA_Init(void)
 	if (dma.samplebits != 16 && dma.samplebits != 8)
     {
         ioctl(audio_fd, SNDCTL_DSP_GETFMTS, &fmt);
-        if (fmt & AFMT_S16_LE) dma.samplebits = 16;
+        if (fmt & AFMT_S16_NE) dma.samplebits = 16;
         else if (fmt & AFMT_U8) dma.samplebits = 8;
     }
 
@@ -157,7 +157,7 @@ qboolean SNDDMA_Init(void)
 
     if (dma.samplebits == 16)
     {
-        rc = AFMT_S16_LE;
+        rc = AFMT_S16_NE;
         rc = ioctl(audio_fd, SNDCTL_DSP_SETFMT, &rc);
         if (rc < 0)
 		{
