--- graphics.c.orig	1989-11-17 22:37:38 UTC
+++ graphics.c
@@ -79,8 +79,8 @@ init_pixmaps(top_shell)
 
 /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
 
-  fgcolor.pixel = fg;
-  bgcolor.pixel = bg;
+  fgcolor.pixel = app_data.fg;
+  bgcolor.pixel = app_data.bg;
   fgcolor.flags =  DoRed | DoGreen | DoBlue;
   bgcolor.flags =  DoRed | DoGreen | DoBlue;
   XQueryColor(display,DefaultColormapOfScreen(XtScreen(playfield_widget)), &fgcolor);
@@ -156,11 +156,11 @@ auto_teleport()
 {
   if(!cant_move)
 	return;
-  if(autoteleport && sonic_used) {
+  if(app_data.autoteleport && sonic_used) {
 	teleport();
 	return;
   }
-  if(autoteleportalways)
+  if(app_data.autoteleportalways)
 	teleport();
 }
 
@@ -171,12 +171,12 @@ display_ok_move(x,y)
 
   if(can_go(x,y)) {
     cant_move = 0;
-    if(!spiffy) return;
+    if(!app_data.spiffy) return;
 			/* show the icon for a good move */
     XDrawPoint(display, playfield, gc, 
                pos_to_coord(x)+CELLSIZE/2,pos_to_coord(y)+CELLSIZE/2);
   } else {
-    if(!spiffy) return;
+    if(!app_data.spiffy) return;
 			/* or erase any previous dross */
     if( INXRANGE(x) && INYRANGE(y) && (robot_array[x][y] == EMPTY))
       XClearArea(display, playfield, 
@@ -370,7 +370,7 @@ void free_pixmaps()
   XFreeCursor(display,stayC);
   XFreeCursor(display,thumbsC);
   XFreeCursor(display,cant_goC);
-  for(i=0;i++;i<NUM_TMP_CURSOR_PIXMAPS) 
+  for(i=0;i<NUM_TMP_CURSOR_PIXMAPS;i++)
     XFreePixmap(display,tmp_pixmap[i]);
 
   XFreePixmap(display,playerP);
@@ -405,7 +405,7 @@ show_teleport()
  */
 unsigned int i;
 
-  if(!spiffy) return;
+  if(!app_data.spiffy) return;
 
   for(i=100;i>0;i-=10) {
     XDrawArc(display,playfield,gc,
@@ -430,7 +430,7 @@ int center_x = pos_to_coord(human_x)+(CE
     center_y = pos_to_coord(human_y)+(CELLSIZE/2)-2;
 int i;
 
-  if(!spiffy) return;
+  if(!app_data.spiffy) return;
 
   for(i=pos_to_coord(human_x-1);i<pos_to_coord(human_x+2);i+=SPACING) {
     XDrawLine(display,playfield,agc,center_x,center_y,i,pos_to_coord(human_y-1));
