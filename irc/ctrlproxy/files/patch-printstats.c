--- printstats.c.orig	Wed Jan  7 09:18:37 2004
+++ printstats.c	Wed Jan  7 09:18:46 2004
@@ -27,9 +27,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
-#include <tdb.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <tdb.h>
 #include <fcntl.h>
 
 int traverse_keys(TDB_CONTEXT *tdb_context, TDB_DATA key, TDB_DATA value, void *pattern)
