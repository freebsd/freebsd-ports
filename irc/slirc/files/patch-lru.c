
$FreeBSD$

--- lru.c.orig	Sun Aug 22 13:14:28 1999
+++ lru.c	Sun Aug 22 17:15:12 2004
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
@@ -283,6 +284,7 @@
 					Col = ColLRUmesg;
 					break;
 				case 'm':
+				break;
 				}
 				SLsmg_set_color(Col);
 			}
