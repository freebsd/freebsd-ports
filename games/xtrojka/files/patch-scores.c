--- scores.c.orig
+++ scores.c
@@ -15,6 +15,7 @@
 
 #include "_strdefs.h"
 
+#include <errno.h>
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/time.h>
@@ -36,8 +37,6 @@
 
 extern flag is_wizard;
 extern time_t last_time;
-
-extern int errno;
 
 int position;
 
