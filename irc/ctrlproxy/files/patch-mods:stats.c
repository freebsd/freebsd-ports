--- mods/stats.c.orig	Wed Dec 10 05:46:40 2003
+++ mods/stats.c	Thu Mar  4 19:08:20 2004
@@ -25,12 +25,10 @@
 #include <stdio.h>
 #include <stdarg.h>
 #include <string.h>
-#include <malloc.h>
-#include <stdio.h>
 #include <time.h>
-#include <tdb.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <tdb.h>
 #include <fcntl.h>
 
 #define MAX_REGEX_SUBMATCHES 30
