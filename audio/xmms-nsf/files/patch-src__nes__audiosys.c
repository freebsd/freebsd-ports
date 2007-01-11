--- ./src/nes/audiosys.c.orig	Sun Jan  7 05:17:57 2001
+++ ./src/nes/audiosys.c	Wed Jan 10 20:10:34 2007
@@ -8,8 +8,11 @@
 
 static NES_AUDIO_HANDLER *nah = 0;
 static NES_VOLUME_HANDLER *nvh = 0;
-void NESAudioRender(Int16 *bufp, Uint buflen)
+Uint32 NESAudioRender(Int16 *bufp, Uint buflen)
 {
+	Int16 x;
+	Uint32 count = 0;
+	
 	while (buflen--)
 	{
 		NES_AUDIO_HANDLER *ph;
@@ -31,9 +34,17 @@
 			else
 				output = accum;
 			output >>= 8;
-			*bufp++ = ((Int32)output) - 0x8000;
+			x = ((Int32)output) - 0x8000;
+			if (abs(x) < 96)
+				count++;
+			else
+				count = 0;
+
+			*bufp++ = x;
 		}
 	}
+
+	return count;
 }
 
 void NESVolume(Uint volume)
