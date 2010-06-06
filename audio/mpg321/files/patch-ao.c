
$FreeBSD$

--- ao.c.orig
+++ ao.c
@@ -229,6 +229,7 @@
            and restore it afterwards */
         signal(SIGINT, SIG_DFL);
         
+        memset(&format, 0, sizeof(format)); 
         format.bits = 16;
         format.rate = header->samplerate;
         format.channels = (options.opt & MPG321_FORCE_STEREO) ? 2 : MAD_NCHANNELS(header);
