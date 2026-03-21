--- src/files.c.orig	2026-02-28 22:45:03 UTC
+++ src/files.c
@@ -76,6 +76,7 @@ const
 
 #if defined(UNIX) && defined(SELECTSAVED)
 #include <sys/types.h>
+#include <limits.h>
 #include <dirent.h>
 #endif
 
