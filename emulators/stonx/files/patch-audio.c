--- audio.c.orig	2004-08-15 14:07:55 UTC
+++ audio.c
@@ -45,6 +45,9 @@ extern int snd_porta;
 #include <linux/sched.h>
 #include <linux/unistd.h>
 #endif
+#elif defined(__FreeBSD__)
+#include <sys/soundcard.h>
+#define SOUND_DEVICE "/dev/dsp"
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 /* NetBSD's Linux API emulation, require -lossaudio too */
 #include <soundcard.h>
@@ -1558,11 +1561,12 @@ void audio_open(void) 
 #if 0
 	child_pid = clone(0,SIGCLD);
 #else
-	child_pid = fork();
+	child_pid = _Fork();
 #endif
 	switch (child_pid)
 	{	case 0: 
 			audio_server();	
+			_exit(0);
 		case -1:
 			fprintf(stderr,"Failed to fork() Audio server\n");
 			break;
