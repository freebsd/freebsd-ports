--- src/tabe_tsiyindbint.c.orig	Sun Nov 11 12:33:08 2001
+++ src/tabe_tsiyindbint.c	Thu Aug 22 02:16:00 2002
@@ -270,3 +270,7 @@
     dbp = (DB *)tsiyindb->dbp;
+#ifndef HAVE_DB3
     errno = dbp->stat(dbp, &sp, NULL, 0);
+#else
+    errno = dbp->stat(dbp, &sp, 0);
+#endif
     if (!errno) {
