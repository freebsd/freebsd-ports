--- src/files.c.orig	Sun Feb 23 23:43:26 2003
+++ src/files.c	Thu Jun 19 11:51:59 2003
@@ -29,6 +29,7 @@
 #endif
 
 #if defined(UNIX) && defined(QT_GRAPHICS)
+#include <limits.h>
 #include <dirent.h>
 #endif
 
