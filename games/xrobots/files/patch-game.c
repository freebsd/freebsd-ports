--- game.c.orig	1995-03-27 12:14:34 UTC
+++ game.c
@@ -34,10 +34,8 @@
  * HP-UX :- following two defines
  */
 
-#define srandom srand
-#define random rand
-
 #include <X11/Intrinsic.h>
+#include <stdlib.h>
 #include "xrobots.h"
 
 /* some of these are global */
@@ -281,7 +279,7 @@ wait_for_em()
       /* backout of latest chase() and break loop */
       undo_chase();
 
-      if(diewaiting) {  	/* for those risk takers out there */
+      if(app_data.diewaiting) {  	/* for those risk takers out there */
         display_level();
         do_death();
         check_score(score);
@@ -294,14 +292,14 @@ wait_for_em()
     add_score(num_wasted);
     if(!num_robots)
 	break;
-    if(showjumps)
+    if(app_data.showjumps)
       show_movement();
     XFlush(display);
   }
   if(!num_robots) 
     new_level();
   else
-    if(!showjumps)
+    if(!app_data.showjumps)
       display_level();
   display_possible_moves();
   auto_teleport();
