--- unarj.c.orig	Wed Jun  5 12:28:06 2002
+++ unarj.c	Mon Nov 29 17:48:27 2004
@@ -54,6 +54,10 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#include <sys/stat.h>
+#include <sys/types.h>
+#include <fcntl.h>
+#include <unistd.h>
 #else /* !MODERN */
 extern void free();
 extern void exit();
@@ -718,6 +722,8 @@
 extract()
 {
     char name[FNAME_MAX];
+    char dir[FNAME_MAX];
+    char *pos;
 
     if (check_flags())
     {
@@ -736,6 +742,21 @@
 
     if (host_os != OS)
         default_case_path(name);
+
+
+    /*
+       8/8/2000 Phil Knirsch: Bugfix to create subdirectories. Unarj didn't
+       do this for a long time, so it's finally fixed.
+    */
+    pos = strchr(name, PATH_CHAR);
+
+    while (pos != NULL)
+    {
+        strncpy(dir, name, pos-name);
+        dir[pos-name] = '\0';
+        mkdir(dir, 0777);
+        pos = strchr(pos+1, PATH_CHAR);
+    }
 
     if (file_exists(name))
     {
