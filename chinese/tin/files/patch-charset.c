--- src/charset.c.orig	Mon Jan 29 18:32:23 2001
+++ src/charset.c	Sat Apr 14 08:50:15 2001
@@ -335,7 +335,7 @@
 
 	for (c = (unsigned char *)buf; *c; c++) {
 #ifdef ENABLE_MBLEN
-		if (!my_isprint(*c) && (t_len = mblen(c, MAX(2,MB_CUR_MAX))) <= 1)
+		if (!my_isprint(*c) && (t_len = mblen(c, MAX(2,MB_CUR_MAX))) <= 1  && *c != 27)
 			*c = '?';
 		while (--t_len > 0)
 			c++;
@@ -364,7 +364,7 @@
 
 	for (c = (unsigned char *)buf; *c; c++) {
 #	ifdef ENABLE_MBLEN
-		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13) && (t_len = mblen(c, MAX(2,MB_CUR_MAX))) <= 1)
+		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13  || *c==27) && (t_len = mblen(c, MAX(2,MB_CUR_MAX))) <= 1)
 			*c = '?';
 		while (--t_len > 0)
 			c++;
