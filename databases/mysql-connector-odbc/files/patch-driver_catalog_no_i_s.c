--- driver/catalog_no_i_s.c.orig	2014-06-19 02:50:16.000000000 +0400
+++ driver/catalog_no_i_s.c	2015-03-26 12:31:13.356945009 +0300
@@ -1093,7 +1093,11 @@
   unsigned long *lengths;
   SQLRETURN rc= SQL_SUCCESS;
 
+#ifdef MARIADB_BASE_VERSION
+  my_init_dynamic_array(&records, sizeof(MY_FOREIGN_KEY_FIELD), 0, 0, 0);
+#else
   my_init_dynamic_array(&records, sizeof(MY_FOREIGN_KEY_FIELD), 0, 0);
+#endif
 
   /* Get the list of tables that match szCatalog and szTable */
   pthread_mutex_lock(&stmt->dbc->lock);
