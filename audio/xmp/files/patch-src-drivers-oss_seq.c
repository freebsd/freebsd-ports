--- src/drivers/oss_seq.c.orig	2008-04-16 20:48:53.000000000 +0200
+++ src/drivers/oss_seq.c	2008-04-16 20:49:05.000000000 +0200
@@ -141,7 +141,6 @@
 #endif
 	if (num > SEQ_NUM_VOICES)
 	    return SEQ_NUM_VOICES;
-	GUS_NUMVOICES (dev, num);
 	break;
     }
 
@@ -151,7 +150,6 @@
 
 static void voicepos(int ch, int pos)
 {
-    GUS_VOICE_POS (dev, ch, pos);
 }
 
 
@@ -204,7 +202,6 @@
 
 static void setpan(struct xmp_context *ctx, int ch, int pan)
 {
-    GUS_VOICEBALA(dev, ch, (pan + 0x80) >> 4)
 }
 
 
