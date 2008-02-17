--- dbdimp.c.orig	2008-02-17 22:36:16.000000000 +0100
+++ dbdimp.c	2008-02-17 22:39:27.000000000 +0100
@@ -2760,7 +2760,11 @@
 
       imp_sth->done_desc = 0;
     }
+#if MYSQL_VERSION_ID > 50122
+    (imp_dbh->mysql).net.client_last_errno= 0;
+#else
     (imp_dbh->mysql).net.last_errno= 0;
+#endif
     return 1;
   }
 }
@@ -3362,7 +3366,11 @@
   }
 
   /* fix from 2.9008 */
+#if MYSQL_VERSION_ID > 50122
+  (imp_dbh->mysql).net.client_last_errno = 0;
+#else
   (imp_dbh->mysql).net.last_errno = 0;
+#endif
 
 #if MYSQL_VERSION_ID >=SERVER_PREPARE_VERSION
   if (imp_sth->use_server_side_prepare)
