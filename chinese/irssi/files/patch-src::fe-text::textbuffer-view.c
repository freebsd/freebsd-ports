--- src/fe-text/textbuffer-view.c.orig	Sun Oct 26 13:45:02 2003
+++ src/fe-text/textbuffer-view.c	Sun Dec 14 01:54:28 2003
@@ -435,7 +435,14 @@
 			unichar chr = get_utf8_char(&end, 6);
 			char_width = utf8_width(chr);
 		} else {
-			char_width = 1;
+			if(term_type==TERM_TYPE_BIG5) {
+				if(is_big5(end[0],end[1]))
+					char_width=2;
+				else
+					char_width=1;
+			} else
+				char_width = 1;
+			end+=char_width-1;
 		}
 
 		xpos += char_width;
