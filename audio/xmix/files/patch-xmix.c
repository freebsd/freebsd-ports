--- xmix.c.orig	2016-07-26 16:19:49 UTC
+++ xmix.c
@@ -77,7 +77,7 @@ to Rick! I'll call this version V2.1
 #include "square_empty.bit"
 #include "square_with_x.bit"
 
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 #define SOUND_FULL_SCALE 100.0
 #define MAX_SOUND_VOL 95
