--- lru.c.orig	Sun Aug 22 20:14:28 1999
+++ lru.c	Sun Jan  7 02:37:54 2001
@@ -253,8 +253,9 @@
 	if (el) {
 		do {
 			if (!(p = index(el->str, '!')))
-				p = "NoBang";
-			len = p - el->str;
+				len = strlen(el->str);
+			else
+				len = p - el->str;
 			if (ix + len > SLtt_Screen_Cols - 2)
 				break;
 			if (ix) {
