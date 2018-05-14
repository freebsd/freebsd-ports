--- src/w_dir.h.orig	2017-08-30 20:49:01 UTC
+++ src/w_dir.h
@@ -64,7 +64,7 @@
 
 extern Widget	popup_dir_text;
 extern void	create_dirinfo(Boolean file_exp, Widget parent, Widget below, Widget *ret_beside, Widget *ret_below, Widget *mask_w, Widget *dir_w, Widget *flist_w, Widget *dlist_w, int file_width, Boolean file_panel);
-extern void	update_file_export_dir(const char *restrict dir);
+extern void	update_file_export_dir(const char *dir);
 
 /* Xdir function declarations. */
 
