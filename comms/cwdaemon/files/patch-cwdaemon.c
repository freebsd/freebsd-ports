--- cwdaemon.c.orig	2006-11-09 04:23:11.000000000 -0500
+++ cwdaemon.c	2013-12-29 10:11:15.000000000 -0500
@@ -89,7 +89,7 @@
 #endif
 #include <limits.h>
 
-#include <cwlib.h>
+#include <libcw.h>
 #include "cwdaemon.h"
 
 /* network vars */
@@ -305,8 +305,6 @@
 {
 	cw_set_frequency (morse_tone);	
 	cw_set_send_speed (morse_speed);
-	cw_set_soundcard_sound (soundcard_sound);
-	cw_set_console_sound (console_sound);
 	cw_set_volume (morse_volume);
 	cw_set_gap (0);
 }
@@ -559,8 +557,6 @@
 				if (valid_sdevice == 1)
 				{
 					debug ("Sound device: %s", message + 2);
-					cw_set_soundcard_sound (soundcard_sound);
-					cw_set_console_sound (console_sound);
 				}
 				break;
 			case 'g':	/* volume */
