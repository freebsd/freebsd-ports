--- src/tea_text_document.c.orig	Tue Jul 13 17:05:42 2004
+++ src/tea_text_document.c	Tue Jul 13 17:11:39 2004
@@ -36,6 +36,7 @@
 #include <stdio.h>
 #include <strings.h>
 #include <unistd.h>
+#include <sys/param.h>
 
 #include "tea_file_nav.h"
 #include "tea_text_document.h"
@@ -1289,12 +1290,13 @@
 
 t_note_page* page_create_new_filenav (void)
 {
+  char buf[MAXPATHLEN];
   t_note_page *page = (t_note_page *) g_malloc (sizeof (t_note_page));
  
   page->hash_filelist = NULL; 
   gchar *fn = (gchar*) g_malloc (2048); 
 
-  if (realpath ((gchar *) get_current_dir_name (), fn))
+  if (getcwd(buf, sizeof(buf)) && realpath (buf, fn))
      page->current_path = fn;	
 
   page->type = 1;
