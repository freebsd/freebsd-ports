--- libspeex.c.orig	Sat Sep 21 13:18:53 2002
+++ libspeex.c	Sat Sep 21 13:23:14 2002
@@ -385,7 +385,7 @@
 							#endif
 
 							speex_bits_rewind(&sbits);
-							speex_decode(spx_decoder, &sbits, outbuff, 1);
+							speex_decode(spx_decoder, &sbits, outbuff);
 							
 							// Converting and clipping check
 							for (i = 0; i < speex_fs->framesize; i++) {
@@ -455,7 +455,7 @@
 							// For multiple frames within packets
 							for (j=0; j < speex_fs->nframes; j++)
 							{
-								speex_decode(spx_decoder, &sbits, outbuff, 0);
+								speex_decode(spx_decoder, &sbits, outbuff);
 								
 								// Converting and clipping check
 								for (i = 0; i < speex_fs->framesize; i++) {
