--- isready.c.orig	Wed Nov  5 16:00:45 2003
+++ isready.c	Tue Sep 20 23:43:45 2005
@@ -1,6 +1,9 @@
 #include <stdio.h>
+#include <inttypes.h>
+#include <sys/types.h>
 #include <sys/select.h>
 #include <sys/time.h>
+#include <string.h>
 
 int isready(int fd);
 
