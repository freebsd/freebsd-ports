--- ./drivers/alsa-midi/alsa_rawmidi.c.orig	2008-05-29 16:26:07.000000000 +0400
+++ ./drivers/alsa-midi/alsa_rawmidi.c	2012-05-16 20:10:24.645166068 +0400
@@ -853,7 +853,7 @@
 			struct timespec ts;
 			ts.tv_sec = 0;
 			ts.tv_nsec = wait_nanosleep;
-			clock_nanosleep(CLOCK_MONOTONIC, 0, &ts, NULL);
+			nanosleep(&ts, NULL);
 		}
 		int res = poll((struct pollfd*)&pfds, npfds, poll_timeout);
 		//debug_log("midi_thread(%s): poll exit: %d", str->name, res);
