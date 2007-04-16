--- patchload.c.orig	Sat Feb  7 17:22:51 1998
+++ patchload.c	Mon Nov 17 22:10:07 2003
@@ -19,7 +19,6 @@
 #ifdef linux
 #include <linux/ultrasound.h>
 #else
-#include <machine/ultrasound.h>
 #endif
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -93,7 +92,6 @@
 
     if (pgm < 0) {
 	use8bit = force8bit;
-	GUS_NUMVOICES(gus_dev, (card_info[gus_dev].nr_voices = 32));
 	SEQ_DUMPBUF();
 	for (i = 0; i < 256; i++)
 	    patchloaded[i] = 0;
