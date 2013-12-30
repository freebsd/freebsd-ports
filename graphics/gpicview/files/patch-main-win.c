--- src/main-win.c.orig	2013-10-23 10:42:02.000000000 +0200
+++ src/main-win.c	2013-12-12 18:26:14.000000000 +0100
@@ -378,7 +378,7 @@
         image_list_sort_by_name( mw->img_list, GTK_SORT_DESCENDING );
         if (image_list_get_first(mw->img_list))
             main_win_open(mw, image_list_get_current_file_path(mw->img_list), zoom);
-        return;
+        return TRUE;
     }
 
 
