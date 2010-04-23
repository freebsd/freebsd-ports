--- ./ymplayer.cpp.orig	2010-04-23 13:49:47.000000000 +0200
+++ ./ymplayer.cpp	2010-04-23 13:49:47.000000000 +0200
@@ -6,7 +6,6 @@
 	Project Page: http://atariarea.krap.pl/stymulator
 	
 	Original ST-Sound GPL library by Arnaud Carre (http://leonard.oxg.free.fr)
-	ALSA (Advanced Linux Sound Architecture) library (http://www.alsa-project.org/)
 
 -----------------------------------------------------------------------------
  *   STYMulator is free software; you can redistribute it and/or modify    *
@@ -35,12 +34,16 @@
 #include "stsoundlib/StSoundLibrary.h"
 #include "ui.h"
 #include "sound.h"
-#include <alsa/asoundlib.h>
+#include <sys/soundcard.h>
+#include <sys/ioctl.h>
+#include <unistd.h>
+#include <fcntl.h>
+#include <errno.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 
-extern snd_pcm_uframes_t period_size;
+extern int period_size;
 bool digi;
 
 int main(int argc, char **argv)
@@ -55,7 +58,7 @@
 bool ff = false;
 bool rew = false;
 	
-char *platform;
+const char *platform;
 
 	if (PLATFORM)
 		platform = "64bit";
@@ -69,30 +72,22 @@
 		return -1;
 	}
 
-	snd_pcm_t *pcm_handle;
-	snd_pcm_hw_params_t *hwparams;
-	snd_pcm_hw_params_alloca(&hwparams);
+        int audio_fd;
 
 	int err;
 	unsigned int buf;
 
-	snd_output_t *output = NULL;
-	char pcm_name[] = "default";
+	char pcm_name[] = "/dev/dsp";
 
 	YMMUSIC *pMusic = ymMusicCreate();
 
 	if (ymMusicLoad(pMusic,argv[1])) {
-
-		if ((err = snd_output_stdio_attach(&output, stdout, 0)) < 0) {
-			printf("Output failed: %s\n", snd_strerror(err));
-			return 0;
-		}
-		if ((err = snd_pcm_open(&pcm_handle, pcm_name, SND_PCM_STREAM_PLAYBACK, 0)) < 0) {
-			printf("Playback open error: %s\n", snd_strerror(err));
+		if ((audio_fd = open(pcm_name, O_WRONLY)) < 0) {
+			printf("device open error: %s\n", strerror(errno));
 			return 0;
 		}
-		if ((err = alsa_init(pcm_handle, hwparams)) < 0) {
-			printf("Setting of hwparams failed: %s\n", snd_strerror(err));
+		if (oss_init(audio_fd) < 0) {
+			printf("Setting of hwparams failed: %s\n", strerror(errno));
 			exit(EXIT_FAILURE);
 		}
 
@@ -113,15 +108,10 @@
 			if (digi)
 				draw_time(ymMusicGetPos(pMusic) / 1000);
 
-			if ((err = snd_pcm_writei(pcm_handle, convertBuffer, buf)) == -EPIPE) {
-				err = snd_pcm_prepare(pcm_handle);
-			} else if (err == -ESTRPIPE) {
-				while ((err = snd_pcm_resume(pcm_handle)) == -EAGAIN)
-				sleep(1);
-				if (err < 0) {
-					err = snd_pcm_prepare(pcm_handle);
-				}
-			}
+			if (write(audio_fd, convertBuffer, buf*2) < 0) {
+                            perror("audio device not ready for data");
+                        }
+                        
 			switch(getch()) {
 				case 27: case 'q':	quit = true; break;
 				case 'z':	pmode = true;	break; //play
@@ -132,6 +122,7 @@
 				case 'n':	rew = true; break;
 			}
 			if (rmode)
+			{
 				if (repeat) {
 					ymMusicSetLoopMode(pMusic,YMTRUE);
 					mvaddstr(pos_y+7,pos_x+67,"Yes");
@@ -143,7 +134,7 @@
 					rmode = false;
 					repeat = true;
 				}
-
+			}
 			if (!stop && playing) {
 				if (pmode && !paused)
 					mvaddstr(pos_y+6,pos_x+67,"Play");	//play
@@ -168,18 +159,20 @@
 				pmode = false;
 			}
 
-			if (ymMusicIsSeekable(pMusic) && digi) 
+			if (ymMusicIsSeekable(pMusic) && digi)
+			{
 				if (ff) {
-				ymMusicSeek(pMusic, ymMusicGetPos(pMusic) + 1000);
-				ff = false;
-			} else if (rew) {
-				ymMusicSeek(pMusic, ymMusicGetPos(pMusic) - 1000);
-				rew = false;
+					ymMusicSeek(pMusic, ymMusicGetPos(pMusic) + 1000);
+					ff = false;
+				} else if (rew) {
+					ymMusicSeek(pMusic, ymMusicGetPos(pMusic) - 1000);
+					rew = false;
+				}
 			}
 		}	
 	
 		ymMusicStop(pMusic);
-		snd_pcm_close(pcm_handle);
+		close(audio_fd);
 		delete convertBuffer;
 		ui_end();
 
