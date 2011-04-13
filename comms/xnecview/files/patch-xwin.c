
commit 02352e102c1913dc232500c7fd80b3947a8593ea
Author: Diego Ongaro <ongardie@gmail.com>
Date:   Sun Jun 29 00:30:09 2008 +0100

    remove depth

diff --git a/xwin.c b/xwin.c
index 31d3cf2..4011c16 100644
--- xwin.c
+++ xwin.c
@@ -39,7 +39,6 @@ GtkLabel *msgwidget;     /* label widget in top right corner, used for several m
 int fontheight;
 GdkPixmap *gbackg2=NULL;      /* for window2, we draw into this pixmap */
 GdkColormap *gcm;
-int depth;
 
 int redraw=1;        /* flag which signifies need for redrawing of struct/gain plot */
 int dragging=0;      /* flag to indicate that user is dragging the struct/gain plot */
@@ -360,7 +359,7 @@ gint resize_event(GtkWidget *w,GdkEventConfigure *ev,gpointer dummy)
    winsizex=ev->width;
    winsizey=ev->height;
    gdk_pixmap_unref(gbackg);
-   gbackg=gdk_pixmap_new(w->window,winsizex,winsizey,depth);
+   gbackg=gdk_pixmap_new(w->window,winsizex,winsizey,gdk_drawable_get_depth(w->window));
    calcproj();
    redraw=1;
 #if 0
@@ -876,7 +875,7 @@ gint resize_event2(GtkWidget *w,GdkEventConfigure *ev,gpointer dummy)
    win2sizex=ev->width;
    win2sizey=ev->height;
    gdk_pixmap_unref(gbackg2);
-   gbackg2=gdk_pixmap_new(w->window,win2sizex,win2sizey,depth);
+   gbackg2=gdk_pixmap_new(w->window,win2sizex,win2sizey,gdk_drawable_get_depth(w->window));
 
    redraw2=1;
    return TRUE;
@@ -1035,10 +1034,12 @@ void cmd_setZ0(GtkEntry *w)
 
 void getcolor(char *name,GdkColor *xc)
 {
+#if 0
    if (depth==1) {          /* on 1bpp displays, choose black for everything except the background */
       if (strcmp(name,C_BG)) name="black";
       else name="white";
    }
+#endif
    gdk_color_parse(name,xc);
    if (!gdk_colormap_alloc_color(gcm,xc,TRUE,FALSE)) {
       /* if allocation failed, use black */
@@ -1210,7 +1211,9 @@ void maininitX(int really)
    {
       GdkVisual *vi;
       vi = gdk_visual_get_best();
+#if 0
       depth=vi->depth;
+#endif
       gcm=gdk_colormap_new(vi,FALSE);
    }
 
@@ -1386,7 +1389,7 @@ void maininitX(int really)
          winsizex=toprow->requisition.width;
          calcproj();
       }
-      gbackg=gdk_pixmap_new(w->window,winsizex,winsizey,depth);
+      gbackg=gdk_pixmap_new(w->window,winsizex,winsizey,gdk_drawable_get_depth(w->window));
 
       upd_msg();
 
@@ -1482,7 +1485,7 @@ void maininitX(int really)
 
       ggc2 = gdk_gc_new(w->window);
 
-      gbackg2=gdk_pixmap_new(w->window,win2sizex,win2sizey,depth);
+      gbackg2=gdk_pixmap_new(w->window,win2sizex,win2sizey,gdk_drawable_get_depth(w->window));
 
       gtk_signal_connect( GTK_OBJECT(w), "expose_event", GTK_SIGNAL_FUNC(expose_event2), NULL);
 


