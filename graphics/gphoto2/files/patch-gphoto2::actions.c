--- gphoto2/actions.c.orig	Thu Sep 30 13:04:05 2004
+++ gphoto2/actions.c	Thu Sep 30 13:14:06 2004
@@ -346,12 +346,13 @@
 {
         ExifEntry *e;
         unsigned int i;
+        char value[1024];
 
         for (i = 0; i < content->count; i++) {
                 e = content->entries[i];
                 printf ("%-20.20s", exif_tag_get_name (e->tag));
                 printf ("|");
-                printf ("%-59.59s", exif_entry_get_value (e));
+                printf ("%-59.59s", exif_entry_get_value (e, value, sizeof(value)));
                 printf ("\n");
         }
 }
