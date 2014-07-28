--- mod.c.orig	Sun Oct 22 04:13:23 1995
+++ mod.c	Sat Jan 27 15:04:15 2001
@@ -11,7 +11,7 @@
 
 
 #ifdef GUS
-#include <sys/ultrasound.h>
+#include <machine/ultrasound.h>
 #include "gus.h"
 #endif /* GUS */
 
@@ -130,8 +130,10 @@
     /* Portamento Down */
     if ((track->period += track->port_down) > track->period_high_limit)
       track->period = track->period_high_limit;
-    track->pitch = track->finetune_rate / track->period;
-
+    if (track->period != 0)
+      track->pitch = track->finetune_rate / track->period;
+    else
+      track->pitch = 1;
     track->playing_period = track->period;
   }
 
