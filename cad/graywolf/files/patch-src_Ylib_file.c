--- src/Ylib/file.c.orig	2020-03-29 06:09:00 UTC
+++ src/Ylib/file.c
@@ -133,7 +133,11 @@ char *pathname ;
 
 } /* end Yfile_slink */
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <dirent.h>
+#else
 #include <sys/dir.h>
+#endif
 
 /* check if a directory exists */
 BOOL YdirectoryExists(pathname)
