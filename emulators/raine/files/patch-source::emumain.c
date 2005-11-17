--- source/emumain.c.orig	Wed Aug 17 13:14:36 2005
+++ source/emumain.c	Thu Nov 17 18:04:37 2005
@@ -9,6 +9,10 @@
 #include <winalleg.h>
 #endif
 
+#ifdef RAINE_UNIX
+#include <sys/time.h>
+#endif
+
 #include "raine.h"              // General defines and stuff
 #include "gui.h"                // Interface stuff
 #include "sasound.h"            // Sound Sample stuff
@@ -286,13 +290,13 @@
       } else if (recording_video) { // if draw_screen
 	int current_video_frame = cpu_frame_count*video_fps / fps;
 	if (current_video_frame != last_video_frame) {
-	  last_video_frame = current_video_frame;
 	  char full_name1[256],full_name2[256];
 	  FILE *f,*f2;
 	  char buffer[1024];
 	  int lus,n;
 	  char *extension = (display_cfg.screenshot_png ? "png" : "pcx");
 
+	  last_video_frame = current_video_frame;
 	  fprintf(stderr,"drop frame\n");
 	  sprintf(full_name2,"%s%s_%06d.%s",dir_cfg.screen_dir, current_game->main_name,cpu_frame_count,extension);
 	  n = 1;
