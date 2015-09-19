--- graphics.c.orig	1991-09-13 20:32:11 UTC
+++ graphics.c
@@ -63,8 +63,8 @@ init_pixmaps(top_shell)
 
 /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
 
-  fgcolor.pixel = fg;
-  bgcolor.pixel = bg;
+  fgcolor.pixel = app_data.fg;
+  bgcolor.pixel = app_data.bg;
   fgcolor.flags =  DoRed | DoGreen | DoBlue;
   bgcolor.flags =  DoRed | DoGreen | DoBlue;
   XQueryColor(display,DefaultColormapOfScreen(XtScreen(playfield_widget)), &fgcolor);
@@ -444,7 +444,7 @@ void free_pixmaps()
 {
   int i;
 
-  for(i=0;i++;i<NUM_TMP_CURSOR_PIXMAPS) 
+  for(i=0;i<NUM_TMP_CURSOR_PIXMAPS;i++)
     XFreePixmap(display,tmp_pixmap[i]);
 
 }
