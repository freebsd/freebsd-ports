--- libcob/fileio.c.orig	Wed Jun 11 15:40:20 2003
+++ libcob/fileio.c	Wed Aug 27 09:57:31 2003
@@ -202,13 +202,10 @@
   else
     {
       /* discard input until the next newline */
-      int c = getc (f->file);
-      while (c != '\r' && c != '\n' && c != EOF)
-	c = getc (f->file);
-      if (c == '\r')
-	c = getc (f->file);
-      if (c != '\n' && c != EOF)
-	ungetc (c, f->file);
+      char buff[BUFSIZ];
+      while (fgets (buff, BUFSIZ, f->file) !=NULL)
+	if (strchr (buff, '\n') != NULL)
+	  break;
     }
 
   memcpy (f->record->data, buff, f->record->size);
