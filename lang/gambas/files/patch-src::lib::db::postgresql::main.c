--- src/lib/db/postgresql/main.c.orig	Sun Aug  3 11:58:41 2003
+++ src/lib/db/postgresql/main.c	Sun Jan 25 14:29:09 2004
@@ -31,7 +31,7 @@
 
 #include <libpq-fe.h>
 #include <postgres.h>
-#include <pg_type.h>
+#include <catalog/pg_type.h>
 
 #include "main.h"
 
