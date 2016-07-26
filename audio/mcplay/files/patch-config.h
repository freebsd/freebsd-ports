--- config.h.orig	2002-04-28 13:30:35 UTC
+++ config.h
@@ -26,7 +26,7 @@
 #define LOGFILE_S LOGDIR_S""G_DIR_SEPARATOR_S""PROGNAME_S".log"
 
 /* if you have linux */
-#include <linux/limits.h>
+#include <sys/limits.h>
 /* else */
 /* #define PATH_MAX 1000 */
 /* #define NAME_MAX 200 */
