--- unarj.c.orig	2002-06-05 08:28:06 UTC
+++ unarj.c
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
@@ -718,6 +722,8 @@ static int
 extract()
 {
     char name[FNAME_MAX];
+    char dir[FNAME_MAX];
+    char *pos;
 
     if (check_flags())
     {
@@ -737,6 +743,21 @@ extract()
     if (host_os != OS)
         default_case_path(name);
 
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
+
     if (file_exists(name))
     {
         printf(M_FEXISTS, name);
