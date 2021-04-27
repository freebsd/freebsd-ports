--- src/files.c.orig	2021-03-22 22:28:14 UTC
+++ src/files.c
@@ -51,6 +51,7 @@ const
 
 #if defined(UNIX) && defined(SELECTSAVED)
 #include <sys/types.h>
+#include <limits.h>
 #include <dirent.h>
 #include <stdlib.h>
 #endif
