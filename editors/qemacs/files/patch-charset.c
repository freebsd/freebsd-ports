--- charset.c.orig	Tue Apr 22 07:01:42 2003
+++ charset.c	Thu Jan 18 13:56:10 2007
@@ -20,7 +20,7 @@
 
 QECharset *first_charset = NULL;
 
-extern QECharset charset_7bit;
+static QECharset charset_7bit;
 
 /* specific tables */
 static unsigned short table_idem[256];
