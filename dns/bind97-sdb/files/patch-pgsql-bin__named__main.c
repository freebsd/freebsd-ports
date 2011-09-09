--- bin/named/main.c.orig	2011-06-10 10:18:35.000000000 -0700
+++ bin/named/main.c	2011-06-10 10:03:45.000000000 -0700
@@ -74,6 +74,7 @@
  * Include header files for database drivers here.
  */
 /* #include "xxdb.h" */
+#include <pgsqldb.h>
 
 /*
  * Include DLZ drivers if appropriate.
@@ -841,6 +842,7 @@
 	 * Add calls to register sdb drivers here.
 	 */
 	/* xxdb_init(); */
+	pgsqldb_init();
 
 #ifdef DLZ
 	/*
@@ -867,6 +869,7 @@
 	 * Add calls to unregister sdb drivers here.
 	 */
 	/* xxdb_clear(); */
+	pgsqldb_clear();
 
 #ifdef DLZ
 	/*
