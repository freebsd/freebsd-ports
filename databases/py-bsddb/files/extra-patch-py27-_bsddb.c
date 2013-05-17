--- ./_bsddb.c.orig	2013-04-06 18:02:34.000000000 +0400
+++ ./_bsddb.c	2013-05-12 09:27:38.000000000 +0400
@@ -9699,7 +9699,7 @@
     ADD_INT(d, DB_RPCCLIENT);
 #endif
 
-#if (DBVER < 48)
+#if (DBVER < 48 || DBVER > 51)
     ADD_INT(d, DB_XA_CREATE);
 #endif
 
