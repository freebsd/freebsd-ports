--- ui.c.orig	2003-11-27 19:42:47 UTC
+++ ui.c
@@ -5,7 +5,9 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
+#include <stdlib.h>
 #include <sys/types.h>
 #include <signal.h>
 #include <curses.h>
@@ -188,8 +190,8 @@ if(need_update)
   {
   need_update=0;
   draw_frame();
-  draw_status(ay_filenames[ay_file],aydata.miscstr,aydata.authorstr,
-              ay_track+1,aydata.tracks[ay_track].namestr);
+  draw_status(ay_filenames[ay_file],(char *)aydata.miscstr, (char *)aydata.authorstr,
+              ay_track+1, (char *)aydata.tracks[ay_track].namestr);
   }
 
 /* update time display */
