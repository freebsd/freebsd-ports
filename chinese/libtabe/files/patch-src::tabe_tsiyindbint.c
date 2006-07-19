--- src/tabe_tsiyindbint.c.orig	Fri Apr 21 23:04:40 2006
+++ src/tabe_tsiyindbint.c	Fri Apr 21 23:04:55 2006
@@ -275,7 +275,9 @@
   switch(tsiyindb->type) {
   case DB_TYPE_DB:
     dbp = (DB *)tsiyindb->dbp;
-#if DB_VERSION >= 303011
+#if DB_VERSION >= 403000
+errno = dbp->stat(dbp, NULL, &sp, 0);
+#elif DB_VERSION >= 303011
     errno = dbp->stat(dbp, &sp, 0);
 #else
     errno = dbp->stat(dbp, &sp, NULL, 0);
