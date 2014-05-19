--- src/tabe_tsidbint.c.orig	Fri Apr 21 23:04:10 2006
+++ src/tabe_tsidbint.c	Fri Apr 21 23:04:33 2006
@@ -272,7 +272,9 @@
   switch(tsidb->type) {
   case DB_TYPE_DB:
     dbp = (DB *)tsidb->dbp;
-#if DB_VERSION >= 303011
+#if DB_VERSION >= 403000
+errno = dbp->stat(dbp, NULL, &sp, 0);
+#elif DB_VERSION >= 303011
     errno = dbp->stat(dbp, &sp, 0);
 #else
     errno = dbp->stat(dbp, &sp, NULL, 0);
