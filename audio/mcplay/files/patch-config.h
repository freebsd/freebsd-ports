--- config.h.orig	2010-03-18 18:48:31.000000000 -0700
+++ config.h	2010-03-18 18:50:27.000000000 -0700
@@ -26,7 +26,7 @@
 #define LOGFILE_S LOGDIR_S""G_DIR_SEPARATOR_S""PROGNAME_S".log"
 
 /* if you have linux */
-#include <linux/limits.h>
+#include <sys/limits.h>
 /* else */
 /* #define PATH_MAX 1000 */
 /* #define NAME_MAX 200 */
