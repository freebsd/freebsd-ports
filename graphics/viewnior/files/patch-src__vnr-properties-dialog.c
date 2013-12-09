--- ./src/vnr-properties-dialog.c.orig	2012-02-25 12:51:26.000000000 +0100
+++ ./src/vnr-properties-dialog.c	2013-12-09 19:13:38.000000000 +0100
@@ -251,7 +251,7 @@
     }
 
 
-    filesize_str = g_format_size_for_display (filesize);
+    filesize_str = g_format_size (filesize);
 
     filetype_desc = g_content_type_get_description (filetype);
 
