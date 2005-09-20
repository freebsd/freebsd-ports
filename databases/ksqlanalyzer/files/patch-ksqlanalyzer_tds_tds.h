
$FreeBSD$

--- ksqlanalyzer/tds/tds.h.orig
+++ ksqlanalyzer/tds/tds.h
@@ -51,9 +51,6 @@
 #include <string.h>
 #include <stdlib.h>
 #include <time.h>
-#ifdef HAVE_MALLOC_H
-#include <malloc.h>
-#endif
 #include <sys/time.h>
 #endif
 
