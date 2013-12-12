--- ./src/main-win.c.orig	2013-12-08 21:46:17.239667539 +0000
+++ ./src/main-win.c	2013-12-08 21:52:52.117640308 +0000
@@ -378,7 +378,7 @@
         image_list_sort_by_name( mw->img_list, GTK_SORT_DESCENDING );
         if (image_list_get_first(mw->img_list))
             main_win_open(mw, image_list_get_current_file_path(mw->img_list), zoom);
-        return;
+        return TRUE;
     }
 
 
