--- db.c.orig	Fri Nov 14 14:41:27 2003
+++ db.c	Fri Nov 14 14:41:35 2003
@@ -32,12 +32,6 @@
 #include "db.h"
 
 /*
-** This function is not an official part of the SQLite API and does
-** not appear in <sqlite.h>.  So we have to supply our own prototype.
-*/
-extern char *sqlite_vmprintf(const char *, ...);
-
-/*
 ** The following is the handle to the open database.
 */
 static sqlite *pDb = 0;
