--- src/gcompris/images_selector.c.orig	Sun Apr 24 00:24:43 2005
+++ src/gcompris/images_selector.c	Sun Apr 24 00:26:06 2005
@@ -609,7 +609,7 @@ item_event_scroll(GnomeCanvasItem *item,
 void
 parseImage (xmlDocPtr doc, xmlNodePtr cur) {
   gchar *imageSetName = NULL;
-  gchar *filename, *pathname, *absolutepath;;
+  gchar *filename, *pathname, *absolutepath;
   GList	*imageList = NULL;	/* List of Images */
   gboolean havePathName = FALSE, lsdir = FALSE;
   gchar *type = NULL;
@@ -793,6 +793,9 @@ read_dataset_directory(gchar *dataset_di
   gchar *fname, *absolute_fname;
 
   while (fname = g_dir_read_name(dataset_directory)) {
+    /* pointer to the new doc */
+    xmlDocPtr doc;
+
     /* skip files without ".xml" */
     if (!g_str_has_suffix (fname,".xml")){
       printf("skipping file not in .xml : %s\n", fname);
@@ -806,9 +809,6 @@ read_dataset_directory(gchar *dataset_di
       continue;
 
     /* parse the new file and put the result into newdoc */
-
-    /* pointer to the new doc */
-    xmlDocPtr doc;
 
     doc = xmlParseFile(absolute_fname);
 
