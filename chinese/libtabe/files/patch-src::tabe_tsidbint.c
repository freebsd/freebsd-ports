--- src/tabe_tsidbint.c.orig	Sun Nov 11 20:33:07 2001
+++ src/tabe_tsidbint.c	Wed Apr  5 13:40:32 2006
@@ -84,8 +84,10 @@
     else {
 #ifndef HAVE_DB3
       errno = db_open(db_name, DB_BTREE, DB_CREATE, 0644, NULL, NULL, &dbp);
-#else
+#elif (DB_VERSION_MAJOR == 3 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR == 0))
       errno = dbp->open(dbp, db_name, NULL, DB_BTREE, DB_CREATE, 0644);
+#else
+      errno = dbp->open(dbp, NULL, db_name, NULL, DB_BTREE, DB_CREATE, 0644);
 #endif
     }
   }
@@ -93,15 +95,19 @@
     if (flags & DB_FLAG_READONLY) {
 #ifndef HAVE_DB3
       errno = db_open(db_name, DB_BTREE, DB_RDONLY, 0444, NULL, NULL, &dbp);
-#else
+#elif (DB_VERSION_MAJOR == 3 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR == 0))
       errno = dbp->open(dbp, db_name, NULL, DB_BTREE, DB_RDONLY, 0444);
+#else
+      errno = dbp->open(dbp, NULL, db_name, NULL, DB_BTREE, DB_RDONLY, 0444);
 #endif
     }
     else {
 #ifndef HAVE_DB3
       errno = db_open(db_name, DB_BTREE, 0, 0644, NULL, NULL, &dbp);
-#else
+#elif (DB_VERSION_MAJOR == 3 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR == 0))
       errno = dbp->open(dbp, db_name, NULL, DB_BTREE, 0, 0644);
+#else
+      errno = dbp->open(dbp, NULL, db_name, NULL, DB_BTREE, 0, 0644);
 #endif
     }
   }
@@ -265,7 +271,13 @@
   switch(tsidb->type) {
   case DB_TYPE_DB:
     dbp = (DB *)tsidb->dbp;
+#ifndef HAVE_DB3
     errno = dbp->stat(dbp, &sp, NULL, 0);
+#elif (DB_VERSION_MAJOR == 3 || (DB_VERSION_MAJOR == 4 && DB_VERSION_MINOR <= 2))
+    errno = dbp->stat(dbp, &sp, 0);
+#else
+    errno = dbp->stat(dbp, NULL, &sp, 0);
+#endif
     if (!errno) {
 #ifndef HAVE_DB3
       return(sp->bt_nrecs);
