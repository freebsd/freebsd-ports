--- src/tabe_tsidbint.c.orig	Sun Nov 11 12:33:07 2001
+++ src/tabe_tsidbint.c	Thu Aug 22 02:14:53 2002
@@ -267,3 +267,7 @@
     dbp = (DB *)tsidb->dbp;
+#ifndef HAVE_DB3
     errno = dbp->stat(dbp, &sp, NULL, 0);
+#else
+    errno = dbp->stat(dbp, &sp, 0);
+#endif
     if (!errno) {
