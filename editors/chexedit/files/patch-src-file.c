--- src/file.c.orig	Wed Jun 30 05:57:15 1999
+++ src/file.c	Sat Mar 17 22:23:57 2001
@@ -19,6 +19,7 @@
 #include <dirent.h>
 #endif
 
+#include <sys/types.h>
 #include <grp.h>
 #include <pwd.h>
 
