--- src/mdh_panel_temp.c.orig	Wed Nov 12 05:36:52 2003
+++ src/mdh_panel_temp.c	Wed Nov 12 05:37:28 2003
@@ -33,9 +33,9 @@
 #include <string.h>
 #include <stdarg.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <regex.h>
 #include <signal.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <time.h>
 #include <wait.h>
