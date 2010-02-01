--- src/common/filechooser.c.orig	2007-09-05 10:18:50.000000000 +0200
+++ src/common/filechooser.c	2010-01-13 21:16:11.000000000 +0100
@@ -19,9 +19,16 @@
  */
 
 #include "filechooser.h"
+#include <sys/param.h>
 
 #ifndef get_current_dir_name
-extern char *get_current_dir_name(void);
+extern char *
+get_current_dir_name(void)
+{
+  char *buf = malloc(MAXPATHLEN);
+  getwd(buf);
+  return buf;
+}
 #endif
 
 /*
