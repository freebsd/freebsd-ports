
$FreeBSD$

--- src/file.c.orig	Sun Jun 10 06:44:19 2001
+++ src/file.c	Tue Apr 30 02:15:40 2002
@@ -148,4 +148,6 @@
 
 		curr = curr->next;
 	}
+	fflush(fp);
+	fsync(fileno(fp));
 }
