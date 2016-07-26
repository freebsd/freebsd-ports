--- util/transname.c.orig	1993-10-02 20:16:00 UTC
+++ util/transname.c
@@ -1,5 +1,5 @@
 #include <sys/types.h>
-#include <sys/dir.h>
+#include <dirent.h>
 
 char *strncpy();
 
