--- mods/stats.c.orig	Wed Jan  7 09:20:11 2004
+++ mods/stats.c	Wed Jan  7 09:20:19 2004
@@ -28,9 +28,9 @@
 #include <malloc.h>
 #include <stdio.h>
 #include <time.h>
-#include <tdb.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <tdb.h>
 #include <fcntl.h>
 
 #define MAX_REGEX_SUBMATCHES 30
