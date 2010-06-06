--- ao-wrapper.c.orig	2010-06-06 14:28:59.000000000 +0200
+++ ao-wrapper.c	2010-06-06 14:29:25.000000000 +0200
@@ -53,6 +53,7 @@ ao_init_16_stereo (int samplerate, int v
 
   default_driver = ao_default_driver_id ();
 
+  memset(&format, 0, sizeof(format));
   format.bits = 16;
   format.channels = 2;
   format.rate = samplerate;
