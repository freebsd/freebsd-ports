--- coresound.c.orig	2006-09-16 13:50:12 UTC
+++ coresound.c
@@ -132,6 +132,7 @@ CoreSound_InitAudio()
 	if (drv < 0)
 		return FALSE;
 
+	memset(&fmt, 0, sizeof(fmt));
 	fmt.rate = sets.samplerate;
 	fmt.bits = 16;
 	fmt.byte_format = AO_FMT_NATIVE;
