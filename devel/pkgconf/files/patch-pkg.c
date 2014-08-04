--- ./pkg.c.orig	2014-06-07 22:32:08.000000000 +0200
+++ ./pkg.c	2014-08-04 11:24:32.524802321 +0200
@@ -212,8 +212,6 @@
 	{
 		char op, *p, *key, *value;
 
-		readbuf[strlen(readbuf) - 1] = '\0';
-
 		p = readbuf;
 		while (*p && (isalpha(*p) || isdigit(*p) || *p == '_' || *p == '.'))
 			p++;
