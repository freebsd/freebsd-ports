--- src/filechooser.c.orig	Mon Jul 16 06:05:22 2007
+++ src/filechooser.c	Mon Jul 23 21:26:21 2007
@@ -19,9 +19,14 @@
  */
 
 #include "filechooser.h"
+#include <sys/param.h>
 
 #ifndef get_current_dir_name
-extern char *get_current_dir_name(void);
+extern char *get_current_dir_name_2() {
+	char *buf = malloc(MAXPATHLEN);
+	getwd(buf);
+	return buf;
+}
 #endif
 
 /*
@@ -325,7 +330,7 @@
   gchar *path;
 
   if (dirname == FILECHOOSER_CWD)
-    path = (gchar *)get_current_dir_name ();
+    path = (gchar *)get_current_dir_name_2 ();
   else
     path = (gchar *)dirname;
 
