--- src/playback.c.orig	2010-06-05 23:11:54.000000000 +0200
+++ src/playback.c	2010-06-05 23:12:22.000000000 +0200
@@ -275,6 +275,7 @@ void playback_open_playdevice(int srate,
            and restore it afterwards */
         signal(SIGINT, SIG_DFL);
         
+        memset(&format, 0, sizeof(format));
         format.bits = bitrate;
         format.rate = srate;
         format.channels = nch;
