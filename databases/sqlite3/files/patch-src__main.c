--- src/main.c.orig	2008-03-04 00:22:33.000000000 -0300
+++ src/main.c	2008-03-04 00:22:45.000000000 -0300
@@ -19,7 +19,7 @@
 #include "sqliteInt.h"
 #include <ctype.h>
 #ifdef SQLITE_ENABLE_FTS3
-# include "fts3.h"
+# include "../ext/fts3/fts3.h"
 #endif
 
 /*
