--- tcltk/tkmap.c.orig	2005-03-12 04:12:22.000000000 +0100
+++ tcltk/tkmap.c	2013-05-14 12:50:05.000000000 +0200
@@ -436,7 +436,7 @@
 	    fraction = 0;
 	    fraction2 = 1;
 	    printf("map xview %g %g\n", fraction, fraction2);
-	    sprintf(interp->result, "%g %g", fraction, fraction2);
+        Tcl_SetResult(interp, "0 1", TCL_STATIC);
 	} else {
 	    type = Tk_GetScrollInfo(interp, argc, argv, &fraction, &count);
 	    switch (type) {
@@ -466,7 +466,7 @@
 	    fraction = 0;
 	    fraction2 = 1;
 	    printf("map yview %g %g\n", fraction, fraction2);
-	    sprintf(interp->result, "%g %g", fraction, fraction2);
+        Tcl_SetResult(interp, "0 1", TCL_STATIC);
 	} else {
 	    type = Tk_GetScrollInfo(interp, argc, argv, &fraction, &count);
 	    switch (type) {
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
