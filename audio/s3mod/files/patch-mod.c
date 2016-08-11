--- mod.c.orig	1995-10-21 19:13:23 UTC
+++ mod.c
@@ -11,7 +11,7 @@
 
 
 #ifdef GUS
-#include <sys/ultrasound.h>
+#include <machine/ultrasound.h>
 #include "gus.h"
 #endif /* GUS */
 
@@ -130,8 +130,10 @@ void beattrack(register track_info_ptr t
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
 
