--- src/fileio.c.orig	Wed Oct 10 15:01:40 2001
+++ src/fileio.c	Sat Apr 15 23:53:31 2006
@@ -1414,6 +1414,12 @@
     gchar *txt;
     gint  stat;
 
+    if (filename != NULL)
+    {
+        return;
+        /* notreached */
+    }
+    
     files = recent_files_get_list();
     if (files == NULL)
     {
