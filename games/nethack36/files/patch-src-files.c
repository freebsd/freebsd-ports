--- src/files.c.orig	2015-12-07 08:26:01 UTC
+++ src/files.c
@@ -40,6 +40,7 @@ const
 
 #if defined(UNIX) && defined(QT_GRAPHICS)
 #include <sys/types.h>
+#include <limits.h>
 #include <dirent.h>
 #include <stdlib.h>
 #endif
