--- src/charset.c.orig	Tue Jan 29 22:31:11 2002
+++ src/charset.c	Fri Mar 22 22:55:40 2002
@@ -335,7 +335,7 @@
 
 	for (c = (unsigned char *)buf; *c; c++) {
 #ifdef ENABLE_MBLEN
-		if (!my_isprint(*c) && (t_len = mblen(c, MAX(2,MB_CUR_MAX))) <= 1)
+		if (!my_isprint(*c) && (t_len = mblen(c, MAX(2,MB_CUR_MAX))) <= 1  && *c != 27)
 			*c = '?';
 		while (--t_len > 0)
 			c++;
@@ -363,7 +363,7 @@
 
 	for (c = (unsigned char *)buf; *c; c++) {
 #ifdef ENABLE_MBLEN
-		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13) && (t_len = mblen(c, MAX(2,MB_CUR_MAX))) <= 1)
+		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13 || *c == 27) && (t_len = mblen(c, MAX(2,MB_CUR_MAX))) <= 1)
 			*c = '?';
 		while (--t_len > 0)
 			c++;
