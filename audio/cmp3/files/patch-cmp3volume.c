--- cmp3volume.c.orig	Sun Jul  1 13:38:08 2001
+++ cmp3volume.c	Sat Mar 20 00:23:51 2004
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
