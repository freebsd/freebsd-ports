--- src/backend.c.orig	Sat Nov 10 01:07:42 2001
+++ src/backend.c	Sat Sep 13 13:10:59 2003
@@ -491,6 +491,7 @@
 	db->changed = 0;
 	db->users = NULL;
 	db->hfiles = NULL;
+	db->nusers = 0;
 
 	return db;
 }
