--- util/transname.c.orig	Fri Apr 16 00:02:36 1999
+++ util/transname.c	Fri Apr 16 00:02:38 1999
@@ -1,5 +1,5 @@
 #include <sys/types.h>
-#include <sys/dir.h>
+#include <dirent.h>
 
 char *strncpy();
 
