--- src/tabe_tsiyindbint.c.orig	Mon May  1 00:49:54 2006
+++ src/tabe_tsiyindbint.c	Mon May  1 00:50:03 2006
@@ -27,6 +27,7 @@
 #endif
 
 #include "tabe.h"
+#define DB_VERSION (DB_VERSION_MAJOR*100000+DB_VERSION_MINOR*1000+DB_VERSION_PATCH)
 
 static void tabeTsiYinDBClose(struct TsiYinDB *tsiyindb);
 static int  tabeTsiYinDBRecordNumber(struct TsiYinDB *tsiyindb);
@@ -72,7 +73,7 @@
 {
   DB *dbp=NULL;
 
-#ifdef HAVE_DB3
+#if DB_VERSION >= 300000
   /* create a db handler */
   if ((errno = db_create(&dbp, NULL, 0)) != 0) {
     fprintf(stderr, "db_create: %s\n", db_strerror(errno));
@@ -85,26 +86,32 @@
       return(NULL);
     }
     else {
-#ifndef HAVE_DB3
-      errno = db_open(db_name, DB_BTREE, DB_CREATE, 0644, NULL, NULL, &dbp);
-#else
+#if DB_VERSION >= 401025
+      errno = dbp->open(dbp, NULL, db_name, NULL, DB_BTREE, DB_CREATE, 0644);
+#elif DB_VERSION >= 300000
       errno = dbp->open(dbp, db_name, NULL, DB_BTREE, DB_CREATE, 0644);
+#else
+      errno = db_open(db_name, DB_BTREE, DB_CREATE, 0644, NULL, NULL, &dbp);
 #endif
     }
   }
   else {
     if (flags & DB_FLAG_READONLY) {
-#ifndef HAVE_DB3
-      errno = db_open(db_name, DB_BTREE, DB_RDONLY, 0444, NULL, NULL, &dbp);
-#else
+#if DB_VERSION >= 401025
+      errno = dbp->open(dbp, NULL, db_name, NULL, DB_BTREE, DB_RDONLY, 0444);
+#elif DB_VERSION >= 300000
       errno = dbp->open(dbp, db_name, NULL, DB_BTREE, DB_RDONLY, 0444);
+#else
+      errno = db_open(db_name, DB_BTREE, DB_RDONLY, 0444, NULL, NULL, &dbp);
 #endif
     }
     else {
-#ifndef HAVE_DB3
-      errno = db_open(db_name, DB_BTREE, 0, 0644, NULL, NULL, &dbp);
-#else
+#if DB_VERSION >= 401025
+      errno = dbp->open(dbp, NULL, db_name, NULL, DB_BTREE, 0, 0644);
+#elif DB_VERSION >= 300000
       errno = dbp->open(dbp, db_name, NULL, DB_BTREE, 0, 0644);
+#else
+      errno = db_open(db_name, DB_BTREE, 0, 0644, NULL, NULL, &dbp);
 #endif
     }
   }
@@ -115,11 +122,11 @@
   }
   if (errno < 0) {
     /* DB specific errno */
-#ifndef HAVE_DB3
+#if DB_VERSION >= 300000
+    fprintf(stderr, "tabeTsiYinDBOpen(): %s.\n", db_strerror(errno));
+#else
     fprintf(stderr, "tabeTsiYinDBOpen(): DB error opening DB File %s.\n",
 	    db_name);
-#else
-    fprintf(stderr, "tabeTsiYinDBOpen(): %s.\n", db_strerror(errno));
 #endif
     return(NULL);
   }
@@ -268,12 +275,18 @@
   switch(tsiyindb->type) {
   case DB_TYPE_DB:
     dbp = (DB *)tsiyindb->dbp;
+#if DB_VERSION >= 403000
+    errno = dbp->stat(dbp, NULL, &sp, 0);
+#elif DB_VERSION >= 303011
+    errno = dbp->stat(dbp, &sp, 0);
+#else
     errno = dbp->stat(dbp, &sp, NULL, 0);
+#endif
     if (!errno) {
-#ifndef HAVE_DB3
-      return(sp->bt_nrecs);
-#else
+#if DB_VERSION >= 300000
       return(sp->bt_ndata);  /* or sp->bt_nkeys? */
+#else
+      return(sp->bt_nrecs);
 #endif
     }
     break;
@@ -481,14 +494,10 @@
     dbcp->c_close(dbcp);
   }
 
-#ifndef HAVE_DB3
-#if DB_VERSION_MINOR > 6 || (DB_VERSION_MINOR == 6 && DB_VERSION_PATCH > 4)
+#if DB_VERSION >= 206004
   dbp->cursor(dbp, NULL, &dbcp, 0);
 #else
   dbp->cursor(dbp, NULL, &dbcp);
-#endif
-#else
-  dbp->cursor(dbp, NULL, &dbcp, 0);
 #endif
   tsiyindb->dbcp = dbcp;
 
