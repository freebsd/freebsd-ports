--- libmuine/db.c.orig	2009-09-13 07:53:58.000000000 -0700
+++ libmuine/db.c	2012-03-30 16:28:25.989121919 -0700
@@ -58,7 +58,7 @@
 	}
 
 	if (db == NULL) {
-		*error_message_return = gdbm_strerror (gdbm_errno);
+		*error_message_return = (char *)gdbm_strerror (gdbm_errno);
 	} else {
 		*error_message_return = NULL;
 	}
