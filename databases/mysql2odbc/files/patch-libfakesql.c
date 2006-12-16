--- libfakesql.c.orig	Sat Dec 16 16:28:53 2006
+++ libfakesql.c	Sat Dec 16 16:30:32 2006
@@ -127,7 +127,7 @@
 {
   TSQLPrivate *pDB;
 
-  DBOF(mysql) = pDB = (TSQLPrivate *) calloc (1, sizeof (TSQLPrivate));
+  mysql->net.vio = pDB = (TSQLPrivate *) calloc (1, sizeof (TSQLPrivate));
   if (pDB == NULL)
     {
       _set_error (mysql, CR_OUT_OF_MEMORY);
@@ -166,7 +166,7 @@
       pDB->hStmt = SQL_NULL_HSTMT;
       pDB->bConnected = 0;
       free (pDB);
-      DBOF(mysql) = NULL;
+      mysql->net.vio = NULL;
     }
 }
 
