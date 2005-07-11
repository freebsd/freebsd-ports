--- dbdimp.c.orig	Mon Jul 11 11:37:03 2005
+++ dbdimp.c	Mon Jul 11 11:37:30 2005
@@ -2772,7 +2772,9 @@
   unsigned long *lengths;
   int rc;
   imp_sth_fbh_t *fbh;
+#if MYSQL_VERSION_ID >=SERVER_PREPARE_VERSION
   MYSQL_BIND *bind;
+#endif
   D_imp_dbh_from_sth;
 
 #if MYSQL_VERSION_ID >=SERVER_PREPARE_VERSION
