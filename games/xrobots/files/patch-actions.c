--- actions.c.orig	2013-10-13 01:20:18.000000000 +1100
+++ actions.c	2013-10-13 01:26:21.000000000 +1100
@@ -66,6 +66,7 @@
   Cardinal *num_params;
 {
   /* do nothing */
+  return NULL;
 }
 
 
@@ -169,11 +170,11 @@
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
@@ -210,14 +211,14 @@
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
@@ -261,7 +262,7 @@
   int tmp_human_x, tmp_human_y;
   int num_wasted;
 
-  if(!game_active) return;
+  if(!game_active) return NULL;
 
   while(direction = determine_direction(event->x,event->y)) {
     if(direction == STILL) break;
