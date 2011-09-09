--- bin/named/main.c.orig	2008-10-23 18:28:08.000000000 -0700
+++ bin/named/main.c	2011-06-10 16:47:50.000000000 -0700
@@ -73,6 +73,7 @@
  * Include header files for database drivers here.
  */
 /* #include "xxdb.h" */
+#include <ldapdb.h> 
 
 /*
  * Include DLZ drivers if appropriate.
@@ -716,6 +717,7 @@
 	 * Add calls to register sdb drivers here.
 	 */
 	/* xxdb_init(); */
+	ldapdb_init();
 
 #ifdef DLZ
 	/*
@@ -742,6 +744,7 @@
 	 * Add calls to unregister sdb drivers here.
 	 */
 	/* xxdb_clear(); */
+	ldapdb_clear();
 
 #ifdef DLZ
 	/*
