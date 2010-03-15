--- src/xfns.c.orig	2009-08-31 00:03:02.000000000 +0100
+++ src/xfns.c	2009-08-31 00:21:39.000000000 +0100
@@ -468,8 +468,10 @@
       if (!FRAME_X_P (f) || FRAME_X_DISPLAY_INFO (f) != dpyinfo)
 	continue;
       x = f->output_data.x;
-      /* Match if the window is this frame's menubar.  */
 #ifdef USE_GTK
+      /* Match if the window is this frame's window (button presses are no longer
+         caught by the menubar) or a menu in the menubar.
+       */
       if (x->menubar_widget)
         {
           GtkWidget *gwdesc = xg_win_to_widget (dpyinfo->display, wdesc);
@@ -477,13 +479,14 @@
 
           BLOCK_INPUT;
           if (gwdesc != 0
-              && (gwdesc == x->menubar_widget
+              && (gwdesc == gtk_widget_get_parent (gtk_widget_get_parent (x->menubar_widget))
                   || gtk_widget_get_parent (gwdesc) == x->menubar_widget))
             found = 1;
           UNBLOCK_INPUT;
           if (found) return f;
         }
 #else
+      /* Match if the window is in this frame's menubar */
       if (x->menubar_widget
 	  && lw_window_is_in_menubar (wdesc, x->menubar_widget))
 	return f;
