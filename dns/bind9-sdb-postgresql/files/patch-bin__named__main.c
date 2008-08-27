--- ./bin/named/main.c.orig	2006-11-10 13:51:14.000000000 -0500
+++ ./bin/named/main.c	2008-08-26 12:01:22.000000000 -0400
@@ -72,6 +72,7 @@
  * Include header files for database drivers here.
  */
 /* #include "xxdb.h" */
+#include <pgsqldb.h>
 
 /*
  * Include DLZ drivers if appropriate.
@@ -681,6 +682,7 @@
 	 * Add calls to register sdb drivers here.
 	 */
 	/* xxdb_init(); */
+	pgsqldb_init();
 
 #ifdef DLZ
 	/*
@@ -707,6 +709,7 @@
 	 * Add calls to unregister sdb drivers here.
 	 */
 	/* xxdb_clear(); */
+	pgsqldb_clear();
 
 #ifdef DLZ
 	/*
