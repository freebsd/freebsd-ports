--- src/main.c.orig	2009-07-10 06:58:20.000000000 +0400
+++ src/main.c	2009-07-18 03:03:19.000000000 +0400
@@ -26,6 +26,9 @@
  */
 
 
+#include <unistd.h>
+#include <err.h>
+#include <sys/stat.h>
 #include <stdio.h>
 #include <time.h>
 #ifdef __WII__
@@ -203,6 +206,9 @@
 int
 main(int ac, char **av)
 {
+	if (chdir(getenv("HOME")) != 0)
+		err(1, "cannot cd to $HOME");
+
 	int status = MTYPE_SUBMENU;
 	bool loop = true;
 	char *path;
