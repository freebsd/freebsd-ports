--- src/file.c.orig	Thu Feb 27 22:04:36 2003
+++ src/file.c	Thu Feb 27 22:05:02 2003
@@ -809,6 +809,7 @@
 rubrica_file_load_xmlfile(gchar *filename, RubricaErrorType* err)
 {
   Rubrica *rubrica;
+  gchar *fpath, *fname;
   
   if (!g_file_exists(filename))
     {
@@ -829,7 +830,6 @@
      now we need to put in memory some information 
      about this file and addressbook      
   */
-  gchar *fpath, *fname;
   
   fpath = g_dirname(filename);
   fname = g_strdup(g_basename(filename));
