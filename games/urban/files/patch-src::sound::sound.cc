--- src/sound/sound.cc.orig	Sun Jan 25 03:58:51 2004
+++ src/sound/sound.cc	Sun Jan 25 04:00:00 2004
@@ -90,7 +90,7 @@
 	md_mode = DMODE_SOFT_SNDFX | DMODE_SOFT_MUSIC | DMODE_16BITS;
 	md_mixfreq = 22050;
         
-	if(MikMod_Init()) {
+	if(MikMod_Init(NULL)) {
         	fprintf(stderr,"Could not initialize sound, reason: %s\n",
                 	MikMod_strerror(MikMod_errno));
 			
