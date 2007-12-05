--- ../common/db.c.orig	2001-08-18 17:52:00.000000000 -0400
+++ ../common/db.c	2007-11-15 13:56:15.000000000 -0500
@@ -164,7 +164,7 @@
 	nlen = 1024;
 retry:
 	/* data.size contains length in bytes */
-	BINC_GOTO(sp, (char *)ep->c_lp, ep->c_blen, nlen);
+	BINC_GOTO(sp, ep->c_lp, ep->c_blen, nlen);
 
 	/* Get the line from the underlying database. */
 	memset(&key, 0, sizeof(key));
