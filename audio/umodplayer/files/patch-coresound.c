--- coresound.c.orig	2010-06-06 14:23:02.000000000 +0200
+++ coresound.c	2010-06-06 14:23:40.000000000 +0200
@@ -132,6 +132,7 @@ CoreSound_InitAudio()
 	if (drv < 0)
 		return FALSE;
 
+	memset(&fmt, 0, sizeof(fmt));
 	fmt.rate = sets.samplerate;
 	fmt.bits = 16;
 	fmt.byte_format = AO_FMT_NATIVE;
