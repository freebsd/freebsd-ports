Since it is the default, the oggenc encoder was moved to the beginning of the
encoder_defaults list in src/gripcfg.c. We set selected_encoder=0 here to
reflect that change. This also prevents the offset from getting screwed up
if encoders are added or removed from the list.

Fix the oggenc arguments. Input file "%w" should be at the end.

--- src/grip.c.orig	2018-01-31 15:06:36 UTC
+++ src/grip.c
@@ -29,6 +29,7 @@
 #include <gdk/gdkx.h>
 #include <X11/Xlib.h>
 #include <time.h>
+#include <sys/wait.h>
 #include "grip.h"
 #include <libgnomeui/gnome-window-icon.h>
 #include "discdb.h"
@@ -897,8 +898,8 @@ static void DoLoadConfig(GripInfo *ginfo)
   ginfo->stop_between_tracks=FALSE;
   *ginfo->wav_filter_cmd='\0';
   *ginfo->disc_filter_cmd='\0';
-  ginfo->selected_encoder=6;
-  strcpy(ginfo->mp3cmdline,"-o %m -a %a -l %d -t %n -b %b %w -N %t -G %G -d %y");
+  ginfo->selected_encoder=0;
+  strcpy(ginfo->mp3cmdline,"-o %m -a %a -l %d -t %n -b %b -N %t -G %G -d %y %w");
   FindExeInPath("oggenc", ginfo->mp3exename, sizeof(ginfo->mp3exename));
   strcpy(ginfo->mp3fileformat,"~/ogg/%A/%d/%t_%n.%x");
   strcpy(ginfo->mp3fileformat_multi,"~/ogg/%A/%d/%t_%a_%n.%x");
