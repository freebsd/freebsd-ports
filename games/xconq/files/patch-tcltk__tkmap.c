--- tcltk/tkmap.c.orig
+++ tcltk/tkmap.c
@@ -976,8 +976,11 @@
     DGprintf("Pixel %d,%d -> unit %s\n", sx, sy, unit_desig(*unitp));
 #endif
     nearest_unit_view(dside, mapw->vp, sx, sy, &uview);
-    if (uview)
+    if (uview) {
       *unitp = view_unit(uview);
+    } else {
+      *unitp = NULL;
+    }
     return TRUE;
 }
 
@@ -3046,7 +3049,7 @@
 	    wid2 = wid / 2;
 	    XSetLineAttributes(dpy, gc, wid, LineSolid, CapButt, JoinMiter); 
 	    color = dside->ui->cell_color[b];
-	    if ((int)color < 0)
+	    if ((long)color < 0)
 	      color = dside->ui->blackcolor;
 	    XSetForeground(dpy, gc, color->pixel);
 	    XSetBackground(dpy, gc, dside->ui->whitecolor->pixel);
@@ -3134,7 +3137,7 @@
 	wid2 = wid / 2;
 	XSetLineAttributes(dpy, gc, wid, LineSolid, CapButt, JoinMiter); 
 	color = dside->ui->cell_color[c];
-	if ((int)color < 0)
+	if ((long)color < 0)
 	  color = dside->ui->blackcolor;
 	XSetForeground(dpy, gc, color->pixel);
 	XSetBackground(dpy, gc, dside->ui->whitecolor->pixel);
@@ -3241,7 +3244,7 @@
 	    wid2 = wid / 2;
 	    XSetLineAttributes(dpy, gc, wid, LineSolid, CapButt, JoinMiter); 
 	    color = dside->ui->cell_color[c];
-	    if ((int)color < 0)
+	    if ((long)color < 0)
 	      color = dside->ui->blackcolor;
 	    XSetForeground(dpy, gc, color->pixel);
 	    XSetBackground(dpy, gc, dside->ui->whitecolor->pixel);
