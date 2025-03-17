--- src/files.c.orig	2025-03-15 15:02:36 UTC
+++ src/files.c
@@ -50,6 +50,7 @@ const
 
 #if defined(UNIX) && defined(SELECTSAVED)
 #include <sys/types.h>
+#include <limits.h>
 #include <dirent.h>
 #endif
 
