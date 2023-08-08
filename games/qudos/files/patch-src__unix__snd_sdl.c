--- src/unix/snd_sdl.c.orig	Thu Sep 13 20:13:49 2007
+++ src/unix/snd_sdl.c	Thu Sep 13 20:17:03 2007
@@ -29,19 +29,18 @@
 #include "../client/client.h"
 #include "../client/snd_loc.h"
 
-static int  snd_inited;
-static dma_t *shm;
+int  snd_inited = 0;
 
 struct sndinfo * si;
 
 static void
 paint_audio (void *unused, Uint8 * stream, int len)
 {
-	if (shm) {
-		shm->buffer = stream;
-		shm->samplepos += len / (shm->samplebits / 4);
-		/* Check for samplepos overflow? */
-		si->S_PaintChannels (shm->samplepos);
+	if (snd_inited) {
+		si->dma->buffer = stream;
+		si->dma->samplepos += len / (si->dma->samplebits / 4);
+		// Check for samplepos overflow?
+		si->S_PaintChannels (si->dma->samplepos);
 	}
 }
 
@@ -50,6 +50,7 @@
 {
 	SDL_AudioSpec desired, obtained;
 	int desired_bits, freq;
+	char	drivername[128];
 	
 	if (SDL_WasInit(SDL_INIT_EVERYTHING) == 0) {
 		if (SDL_Init(SDL_INIT_AUDIO) < 0) {
@@ -68,19 +69,11 @@
 		
 	/* Set up the desired format */
 	freq = si->s_khz->value;
-	
-	if (freq == 48) {
-		desired.freq = 48000;
-	}
-	else if (freq == 44) {
-		desired.freq = 44100;
-	}
-	else if (freq == 22) {
-		desired.freq = 22050;
-	}
-	else {
-		desired.freq = 11025;
-	}
+	if (freq == 48)      desired.freq = 48000;
+	else if (freq == 44) desired.freq = 44100;
+	else if (freq == 22) desired.freq = 22050;
+	else if (freq == 11) desired.freq = 11025;
+	else                 desired.freq = 44100;
 	
 	switch (desired_bits) {
 		case 8:
@@ -96,20 +89,14 @@
 			si->Com_Printf ("Unknown number of audio bits: %d\n", desired_bits);
 			return 0;
 	}
+        
 	desired.channels = si->sndchannels->value;
-	
-	if (desired.freq == 48000) {
-		desired.samples = 4096;
-	}
-	else if (desired.freq == 44100) {
-		desired.samples = 2048;
-	}
-	else if (desired.freq == 22050) {
-		desired.samples = 1024;
-	}
-	else {
-		desired.samples = 512;
-	}
+        
+	if (desired.freq == 48000)      desired.samples = 4096;
+	else if (desired.freq == 44100) desired.samples = 2048;
+	else if (desired.freq == 22050) desired.samples = 1024;
+	else if (desired.freq == 11025) desired.samples = 512;
+	else                            desired.samples = 2048;
 		
 	desired.callback = paint_audio;
 	
@@ -133,7 +120,6 @@
 				/* Supported */
 				break;
 			}
-			/* Unsupported, fall through */ ;
 		default:
 			/* Not supported -- force SDL to do our bidding */
 			SDL_CloseAudio ();
@@ -147,16 +133,21 @@
 	SDL_PauseAudio (0);
 
 	/* Fill the audio DMA information block */
-	shm = si->dma;
-	shm->samplebits = (obtained.format & 0xFF);
-	shm->speed = obtained.freq;
-	shm->channels = obtained.channels;
-	shm->samples = obtained.samples * shm->channels;
-	shm->samplepos = 0;
-	shm->submission_chunk = 1;
-	shm->buffer = NULL;
+	si->dma->samplebits = (obtained.format & 0xFF);
+	si->dma->speed = obtained.freq;
+	si->dma->channels = obtained.channels;
+	si->dma->samples = obtained.samples * si->dma->channels;
+	si->dma->samplepos = 0;
+	si->dma->submission_chunk = 1;
+	si->dma->buffer = NULL;
 
-	si->Com_Printf("\nInitializing SDL Sound System\n");
+	if (SDL_AudioDriverName(drivername, sizeof (drivername)) == NULL)
+		strcpy(drivername, "(UNKNOWN)");
+
+	si->Com_Printf("Initializing SDL Sound System\n");
+	si->Com_Printf("Audio driver: %s\n", drivername);
+	si->Com_Printf("DMA buffer address: 0x%x \n", (int) si->dma->buffer);
+	si->Com_Printf("Channels: %5d\n", MAX_CHANNELS);
 
 	snd_inited = 1;
 	return 1;
@@ -165,12 +156,13 @@
 int
 SNDDMA_GetDMAPos (void)
 {
-	return shm->samplepos;
+	return si->dma->samplepos;
 }
 
 void
 SNDDMA_Shutdown (void)
 {
+	si->Com_Printf("SNDDMA_Shutdown\n");
 	if (snd_inited) {
 		SDL_CloseAudio ();
 		snd_inited = 0;
@@ -183,8 +175,8 @@
 }
 
 /*
-	SNDDMA_Submit
-	Send sound to device if buffer isn't really the dma buffer
+SNDDMA_Submit
+Send sound to device if buffer isn't really the dma buffer
 */
 void
 SNDDMA_Submit (void)
