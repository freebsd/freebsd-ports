--- src/file-utils.h.orig	Sun Jul  3 19:11:59 2005
+++ src/file-utils.h	Sun Jul  3 19:12:52 2005
@@ -25,8 +25,13 @@
 
 #include <sys/types.h>
 #include <time.h>
+#include <stdlib.h>
+#include <limits.h>
 #include <libgnomevfs/gnome-vfs-file-size.h>
 #include <libgnomevfs/gnome-vfs-mime-handlers.h>
+
+#undef fr_atoll
+#define fr_atoll(nptr) strtoll(nptr, (char **)NULL, 10)
 
 
 #define FILENAME_MAX_LENGTH 30 /* FIXME: find out the best value */
