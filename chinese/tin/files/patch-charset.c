--- src/charset.c.orig	Mon Jul 24 21:30:22 2000
+++ src/charset.c	Sat Sep 23 14:03:14 2000
@@ -330,7 +330,7 @@
 	unsigned char *c;
 
 	for (c= (unsigned char *)buf; *c; c++) {
-		if (!my_isprint(*c))
+		if (!my_isprint(*c) && *c != 27)
 			*c = '?';
 	}
 }
@@ -348,7 +348,7 @@
 	unsigned char *c;
 
 	for (c = (unsigned char *)buf; *c; c++) {
-		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13))
+		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13 || *c==27))
 			*c = '?';
 	}
 }
