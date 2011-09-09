--- bin/named/pgsqldb.c.orig	2011-06-10 12:54:44.000000000 -0700
+++ bin/named/pgsqldb.c	2011-06-10 12:56:42.000000000 -0700
@@ -23,7 +23,7 @@
 #include <string.h>
 #include <stdlib.h>
 
-#include <pgsql/libpq-fe.h>
+#include <libpq-fe.h>
 
 #include <isc/mem.h>
 #include <isc/print.h>
