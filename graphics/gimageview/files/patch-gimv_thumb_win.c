--- src/gimv_thumb_win.c.orig	Sun Sep 19 17:48:05 2004
+++ src/gimv_thumb_win.c	Sun Sep 19 17:52:20 2004
@@ -202,7 +202,7 @@
                                      guint          action,
                                      GtkWidget     *widget);
 static void cb_move_tab             (GimvThumbWin  *tw,
-                                     GimvSortItem   sortitem,
+                                     MoveTabItem   item,
                                      GtkWidget     *widget);
 static void cb_cut_out_tab          (GimvThumbWin  *tw,
                                      guint          action,
@@ -1215,7 +1215,9 @@
 }
 
 
+#if 0
 #warning should be implemented as customizable launcher.
+#endif
 static void
 cb_wallpaper_setting (GtkWidget *menuitem, GimvThumbWin *tw)
 {
