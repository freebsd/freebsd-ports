--- librdf/db.c.orig	Tue Oct  3 20:23:27 2000
+++ librdf/db.c	Mon Jan  2 12:06:39 2006
@@ -169,7 +169,11 @@
     }
   }
 
+#if DB_VERSION_MAJOR * 10 + DB_VERSION_MINOR > 40
+  err = (*db)->open(*db, NULL, name, NULL, type, DB_CREATE | DB_THREAD , 0664);
+#else
   err = (*db)->open(*db, name, NULL, type, DB_CREATE | DB_THREAD , 0664);
+#endif
   if (err) {
     printf("Problems opening %s : %s\n", name, db_strerror(err));
     return err;
