--- src/fe-text/textbuffer-view.c.orig	Tue Oct 15 02:45:08 2002
+++ src/fe-text/textbuffer-view.c	Sat Nov 23 18:04:04 2002
@@ -199,8 +199,14 @@
 		}
 
 		if (!view->utf8) {
-			next_ptr = ptr+1;
+			/* MH */
 			char_len = 1;
+			if(ptr[1] != '\0' && is_big5(ptr[0], ptr[1]))
+			{
+			  char_len = 2;
+			}
+			next_ptr = ptr+char_len;
+			/*    */
 		} else {
 			char_len = 1;
 			while (ptr[char_len] != '\0' && char_len < 6)
@@ -251,7 +257,15 @@
 			continue;
 		}
 
-		if (*ptr == ' ') {
+		/* MH */
+		if (!view->utf8 && char_len > 1)
+		{
+			last_space = xpos;
+			last_space_ptr = next_ptr;
+			last_color = color;
+		}
+		/*    */
+		else if (*ptr == ' ') {
 			last_space = xpos;
 			last_space_ptr = ptr;
 			last_color = color;
