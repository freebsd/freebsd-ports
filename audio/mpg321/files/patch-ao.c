--- ao.c.orig	2002-03-24 05:49:47 UTC
+++ ao.c
@@ -229,6 +229,7 @@ void open_ao_playdevice(struct mad_heade
            and restore it afterwards */
         signal(SIGINT, SIG_DFL);
         
+        memset(&format, 0, sizeof(format)); 
         format.bits = 16;
         format.rate = header->samplerate;
         format.channels = (options.opt & MPG321_FORCE_STEREO) ? 2 : MAD_NCHANNELS(header);
