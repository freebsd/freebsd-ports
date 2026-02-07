--- linux/audio.c.orig	2010-06-06 14:56:20.000000000 +0200
+++ linux/audio.c	2010-06-06 14:56:41.000000000 +0200
@@ -166,6 +166,7 @@ static int SoundInit_ao()
   if (driver_id < 0) { driver_id = ao_default_driver_id(); }
 
   ao_sample_format driver_format;
+  memset(&driver_format, 0, sizeof(driver_format));
   driver_format.bits = 16;
   driver_format.channels = StereoSound+1;
   driver_format.rate = freqtab[SoundQuality = ((SoundQuality > 6) ? 1 : SoundQuality)];
