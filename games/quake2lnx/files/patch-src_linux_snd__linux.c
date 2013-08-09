--- src/linux/snd_linux.c.orig	2002-02-10 06:09:23.000000000 +0800
+++ src/linux/snd_linux.c	2013-08-09 20:43:48.000000000 +0800
@@ -25,13 +25,9 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <sys/mman.h>
 #include <sys/shm.h>
 #include <sys/wait.h>
-#if defined(__FreeBSD__)
 #include <sys/soundcard.h>
-#endif
-#if defined(__linux__)
-#include <linux/soundcard.h>
-#endif
 #include <stdio.h>
+#include <unistd.h>
 
 #include "../client/client.h"
 #include "../client/snd_loc.h"
@@ -45,6 +41,7 @@ cvar_t *sndchannels;
 cvar_t *snddevice;
 
 static int tryrates[] = { 11025, 22051, 44100, 48000, 8000 };
+static unsigned long mmaplen;
 
 qboolean SNDDMA_Init(void)
 {
@@ -53,6 +50,7 @@ qboolean SNDDMA_Init(void)
 	int fmt;
 	int tmp;
 	int i;
+	unsigned long sz;
 	struct audio_buf_info info;
 	int caps;
 	extern uid_t saved_euid;
@@ -65,7 +63,7 @@ qboolean SNDDMA_Init(void)
 	if (!snddevice)
 	{
 		sndbits = Cvar_Get("sndbits", "16", CVAR_ARCHIVE);
-		sndspeed = Cvar_Get("sndspeed", "0", CVAR_ARCHIVE);
+		sndspeed = Cvar_Get("sndspeed", "44100", CVAR_ARCHIVE);
 		sndchannels = Cvar_Get("sndchannels", "2", CVAR_ARCHIVE);
 		snddevice = Cvar_Get("snddevice", "/dev/dsp", CVAR_ARCHIVE);
 	}
@@ -76,7 +74,7 @@ qboolean SNDDMA_Init(void)
 	{
 		seteuid(saved_euid);
 
-		audio_fd = open(snddevice->string, O_RDWR);
+		audio_fd = open(snddevice->string, O_RDWR|O_NONBLOCK);
 
 		if (audio_fd == -1)
 		{
@@ -115,28 +113,19 @@ qboolean SNDDMA_Init(void)
 		return 0;
 	}
 
-	if (ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info)==-1)
-	{   
-		perror("GETOSPACE");
-		Com_Printf("SNDDMA_Init: GETOSPACE ioctl failed.\n");
-		close(audio_fd);
-		audio_fd = -1;
-		return 0;
-	}
-    
 // set sample bits & speed
 
 	dma.samplebits = (int)sndbits->value;
 	if (dma.samplebits != 16 && dma.samplebits != 8)
 	{
 		ioctl(audio_fd, SNDCTL_DSP_GETFMTS, &fmt);
-		if (fmt & AFMT_S16_LE) dma.samplebits = 16;
+		if (fmt & AFMT_S16_NE) dma.samplebits = 16;
 		else if (fmt & AFMT_U8) dma.samplebits = 8;
 	}
 
 	if (dma.samplebits == 16)
 	{
-        	rc = AFMT_S16_LE;
+        	rc = AFMT_S16_NE;
 		rc = ioctl(audio_fd, SNDCTL_DSP_SETFMT, &rc);
 		if (rc < 0)
 		{
@@ -211,15 +200,27 @@ qboolean SNDDMA_Init(void)
 		return 0;
 	}
 
+	rc = ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &info);
+	if (rc < 0)
+	{
+		perror("GETOSPACE");
+		Com_Printf("SNDDMA_Init: GETOSPACE ioctl failed.\n");
+		close(audio_fd);
+		audio_fd = -1;
+		return 0;
+	}
+
 	dma.samples = info.fragstotal * info.fragsize / (dma.samplebits/8);
 	dma.submission_chunk = 1;
 
 // memory map the dma buffer
-
+	mmaplen = info.fragstotal * info.fragsize;
+	sz = sysconf (_SC_PAGESIZE);
+	mmaplen += sz - 1;
+	mmaplen &= ~(sz - 1);
 	if (!dma.buffer)
-		dma.buffer = (unsigned char *) mmap(NULL, info.fragstotal
-			* info.fragsize, PROT_WRITE|PROT_READ, MAP_FILE|MAP_SHARED, audio_fd, 0);
-	if (!dma.buffer || dma.buffer == MAP_FAILED)
+		dma.buffer = (unsigned char *) mmap(NULL, mmaplen, PROT_WRITE|PROT_READ, MAP_FILE|MAP_SHARED, audio_fd, 0);
+	if (dma.buffer == MAP_FAILED)
 	{
 		perror(snddevice->string);
 		Com_Printf("SNDDMA_Init: Could not mmap %s.\n", snddevice->string);
@@ -236,6 +237,8 @@ qboolean SNDDMA_Init(void)
 	{
 		perror(snddevice->string);
 		Com_Printf("SNDDMA_Init: Could not toggle. (1)\n");
+		munmap (dma.buffer, mmaplen);
+		dma.buffer=NULL;
 		close(audio_fd);
 		audio_fd = -1;
 		return 0;
@@ -246,6 +249,8 @@ qboolean SNDDMA_Init(void)
 	{
 		perror(snddevice->string);
 		Com_Printf("SNDDMA_Init: Could not toggle. (2)\n");
+		munmap (dma.buffer, mmaplen);
+		dma.buffer=NULL;
 		close(audio_fd);
 		audio_fd = -1;
 		return 0;
@@ -267,6 +272,8 @@ int SNDDMA_GetDMAPos(void)
 	{
 		perror(snddevice->string);
 		Com_Printf("SNDDMA_GetDMAPos: GETOPTR failed.\n");
+		munmap (dma.buffer, mmaplen);
+		dma.buffer=NULL;
 		close(audio_fd);
 		audio_fd = -1;
 		snd_inited = 0;
@@ -284,6 +291,8 @@ void SNDDMA_Shutdown(void)
 #if 0
 	if (snd_inited)
 	{
+		munmap (dma.buffer, mmaplen);
+		dma.buffer=NULL;
 		close(audio_fd);
 		audio_fd = -1;
 		snd_inited = 0;
