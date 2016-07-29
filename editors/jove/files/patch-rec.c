--- rec.c.orig	1996-03-07 17:34:43 UTC
+++ rec.c
@@ -55,8 +55,12 @@ recinit()
 #endif
 		);
 	recfname = copystr(buf);
+#ifndef NO_MKSTEMP
+	rec_fd = mkstemp(recfname);
+#else
 	recfname = mktemp(recfname);
 	rec_fd = creat(recfname, 0644);
+#endif
 	if (rec_fd == -1) {
 		complain("Cannot create \"%s\"; recovery disabled.", recfname);
 		/*NOTREACHED*/
