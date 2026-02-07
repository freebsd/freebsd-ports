--- Table.c.orig	Wed Oct 30 22:35:52 2002
+++ Table.c	Wed Oct 30 23:11:30 2002
@@ -229,7 +229,7 @@
     /* always_install_accelerators */	False,
 #if XmVersion > 1000
     /* geo_matrix_create */	NULL,
-    /* focus_moved_proc */	XtInheritFocusMovedProc,
+    /* focus_moved_proc */	/*XtInheritFocusMovedProc,*/
 #endif
     /* extension	*/  NULL,
   },
@@ -967,7 +967,7 @@
     
 /*    XtMoveWidget(w, rx, ry);*/
 #if 1
-    _XmMoveObject((RectObj) w, rx, ry);
+    _XmMoveObject( w, rx, ry);
 #else
     _XmMoveObject( w, rx, ry);
 #endif
@@ -1020,7 +1020,7 @@
 		w, nw, nh,
 		w->core.border_width);
 #endif
-	    _XmResizeObject((RectObj) managed->locs[i].w, nw, nh,
+	    _XmResizeObject( managed->locs[i].w, nw, nh,
 			    managed->locs[i].w->core.border_width);
 	}
     
