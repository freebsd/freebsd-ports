--- src/file.c.orig	Sun Sep 29 02:35:33 2002
+++ src/file.c	Sun Sep 29 02:35:43 2002
@@ -44,7 +44,9 @@
 #include <sys/stat.h>
 #include <stdlib.h>
 
+#ifndef __FreeBSD__
 extern char *malloc();
+#endif
 
 extern Widget textwindow;
 extern Widget labelwindow;
