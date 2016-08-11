--- cmp3volume.c.orig	2001-07-01 04:38:08 UTC
+++ cmp3volume.c
@@ -3,11 +3,7 @@
 */    
 
 #include "cmp3funcs.h"
-#if defined(__FreeBSD__)
-#include <machine/soundcard.h>
-#else
 #include<sys/soundcard.h>
-#endif
 
 static int mixernum,                    /* ID number for the mixer */
            vol;                         /* Current volume level */
