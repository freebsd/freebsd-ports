--- zphoto.c.orig	Tue Jan 28 19:18:20 2003
+++ zphoto.c	Fri Jan 31 01:34:57 2003
@@ -248,7 +248,7 @@
     int width, height;
     char *photo_width, *photo_height;
 
-    photo_file_name = basename(options->input_photos[id]);
+    photo_file_name = zphoto_strdup(basename(options->input_photos[id]));
     if (id > 0)
         prev_file_name = 
             zphoto_modify_suffix(basename(options->input_photos[id - 1]),
@@ -283,6 +283,7 @@
     zphoto_create_date_string(date_string, BUFSIZ,
                               zphoto_get_mtime(options->input_photos[id]));
     zphoto_template_add_subst(template, "photo_date", date_string);
+    free(photo_file_name);
     free(prev_file_name);
     free(next_file_name);
     free(photo_width);
