--- exiftran.c.orig	Tue Dec 23 19:40:41 2003
+++ exiftran.c	Tue Aug  2 11:38:18 2005
@@ -22,7 +22,8 @@
 #ifdef HAVE_LIBEXIF
 static void dump_exif(FILE *out, ExifData *ed)
 {
-    const char *title, *value;
+    const char *title;
+    char value[1024];
     ExifEntry  *ee;
     int tag,i;
 
@@ -35,7 +36,7 @@
 	    ee = exif_content_get_entry (ed->ifd[i], tag);
 	    if (NULL == ee)
 		continue;
-	    value = exif_entry_get_value(ee);
+	    exif_entry_get_value(ee, value, sizeof(value));
 	    fprintf(out,"      0x%04x  %-30s %s\n", tag, title, value);
 	}
     }
