--- src/gdisplay.c.orig	Mon Jul 16 06:05:23 2007
+++ src/gdisplay.c	Mon Jul 23 20:28:31 2007
@@ -19,9 +19,14 @@
 
 #include "gdisplay.h"
 #include "language.h"
+#include <sys/param.h>
 
 #ifndef get_current_dir_name
-extern char *get_current_dir_name(void);
+extern char *get_current_dir_name() {
+	char *buf = malloc(MAXPATHLEN);
+	getwd(buf);
+	return buf;
+}
 #endif
 
 static gdisplay_t global;	/* (protected) encapsulated program data */
