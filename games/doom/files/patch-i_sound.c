--- linuxdoom-1.10/i_sound.c.orig	Mon Dec 22 20:57:15 1997
+++ linuxdoom-1.10/i_sound.c	Wed Feb 10 04:18:53 1999
@@ -42,7 +42,7 @@
 #include <sys/ioctl.h>
 
 // Linux voxware output.
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 // Timer stuff. Experimental.
 #include <time.h>
@@ -740,11 +740,13 @@
 #ifdef SNDSERV
   char buffer[256];
   
+#if jmz
   if (getenv("DOOMWADDIR"))
     sprintf(buffer, "%s/%s",
 	    getenv("DOOMWADDIR"),
 	    sndserver_filename);
   else
+#endif
     sprintf(buffer, "%s", sndserver_filename);
   
   // start sound process
