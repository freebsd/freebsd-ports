--- src/charset.c.orig	Wed Apr 24 18:41:18 2002
+++ src/charset.c	Sun May 26 13:33:00 2002
@@ -333,7 +333,7 @@
 
 	for (c = (unsigned char *) buf; *c; c++) {
 #ifdef ENABLE_MBLEN
-		if (!my_isprint(*c) && (t_len = mblen((const char *) c, MAX(2,MB_CUR_MAX))) <= 1)
+		if (!my_isprint(*c) && (t_len = mblen((const char *) c, MAX(2,MB_CUR_MAX))) <= 1 && *c != 27)
 			*c = '?';
 		while (--t_len > 0)
 			c++;
@@ -361,7 +361,7 @@
 
 	for (c = (unsigned char *)buf; *c; c++) {
 #ifdef ENABLE_MBLEN
-		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13) && (t_len = mblen((const char *) c, MAX(2,MB_CUR_MAX))) <= 1)
+		if (!(my_isprint(*c) || *c == 8 || *c == 9 || *c == 10 || *c == 12 || *c == 13 || *c == 27 ) && (t_len = mblen((const char *) c, MAX(2,MB_CUR_MAX))) <= 1)
 			*c = '?';
 		while (--t_len > 0)
 			c++;
