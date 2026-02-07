--- ao-wrapper.c.orig	2007-10-14 06:19:36 UTC
+++ ao-wrapper.c
@@ -53,6 +53,7 @@ ao_init_16_stereo (int samplerate, int v
 
   default_driver = ao_default_driver_id ();
 
+  memset(&format, 0, sizeof(format));
   format.bits = 16;
   format.channels = 2;
   format.rate = samplerate;
