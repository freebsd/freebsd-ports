--- actions.c.orig	1989-11-17 22:37:37 UTC
+++ actions.c
@@ -37,6 +37,7 @@
 #include <X11/Intrinsic.h>
 #include <X11/StringDefs.h>
 #include <math.h>
+#include <stdlib.h>
 #include "xrobots.h"
 
 extern Widget sonic_command;
@@ -66,6 +67,7 @@ do_nothing_action(w,event,params,num_par
   Cardinal *num_params;
 {
   /* do nothing */
+  return NULL;
 }
 
 
@@ -169,11 +171,11 @@ move_action(w,event,params,num_params)
   int diff_x, diff_y;
   int num_wasted;
 
-  if(!game_active) return;
+  if(!game_active) return NULL;
 
   if(get_next_position(&diff_x, &diff_y, event->x, event->y,
                         params, *num_params))
-	return;
+	return NULL;
 
   last_human_x = human_x;
   last_human_y = human_y;
@@ -210,14 +212,14 @@ jump_action(w,event,params,num_params)
   int diff_x, diff_y;
   int num_wasted;
 
-  if(!game_active) return;
+  if(!game_active) return NULL;
 
   if(get_next_position(&diff_x, &diff_y, event->x, event->y,
                         params, *num_params))
-	return;
+	return NULL;
 
   if(! can_go(human_x+diff_x,human_y+diff_y) ) 
-	return;
+	return NULL;
 
   while( can_go(human_x+diff_x,human_y+diff_y) ) {
     last_human_x = human_x;
@@ -225,7 +227,7 @@ jump_action(w,event,params,num_params)
     human_x += diff_x;
     human_y += diff_y;
     num_wasted = chase(0);
-    if(showjumps)
+    if(app_data.showjumps)
       show_movement();
     add_score(num_wasted);
     if(!num_robots) 
@@ -235,7 +237,7 @@ jump_action(w,event,params,num_params)
   if(!num_robots)
     new_level();
   else 
-    if(!showjumps)
+    if(!app_data.showjumps)
       display_level();
   display_possible_moves();
   auto_teleport();
@@ -261,7 +263,7 @@ go_here_action(w,event,params,num_params
   int tmp_human_x, tmp_human_y;
   int num_wasted;
 
-  if(!game_active) return;
+  if(!game_active) return NULL;
 
   while(direction = determine_direction(event->x,event->y)) {
     if(direction == STILL) break;
@@ -280,19 +282,19 @@ go_here_action(w,event,params,num_params
     human_x = tmp_human_x;
     human_y = tmp_human_y;
     num_wasted = chase(0);
-    if(showjumps)
+    if(app_data.showjumps)
       show_movement();
     add_score(num_wasted);
     if(!num_robots)
       break;
-    if(spiffy) 
+    if(app_data.spiffy) 
       pointer_moved((Widget)0,(caddr_t)0,event);
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
