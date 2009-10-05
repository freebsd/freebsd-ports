--- ./src/drivers/oss_seq.c.orig	2009-10-05 14:12:41.000000000 +0200
+++ ./src/drivers/oss_seq.c	2009-10-05 14:14:09.000000000 +0200
@@ -138,7 +138,6 @@
 #endif
 		if (num > SEQ_NUM_VOICES)
 			return SEQ_NUM_VOICES;
-		GUS_NUMVOICES(dev, num);
 		break;
 	}
 
@@ -147,7 +146,6 @@
 
 static void voicepos(int ch, int pos)
 {
-	GUS_VOICE_POS(dev, ch, pos);
 }
 
 static void echoback(int msg)
@@ -194,7 +192,6 @@
 
 static void setpan(struct xmp_context *ctx, int ch, int pan)
 {
-	GUS_VOICEBALA(dev, ch, (pan + 0x80) >> 4)
 }
 
 static void setbend(int ch, int bend)
