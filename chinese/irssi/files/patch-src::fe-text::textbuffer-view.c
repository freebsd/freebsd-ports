--- src/fe-text/textbuffer-view.c.orig	Fri Feb 15 22:10:10 2002
+++ src/fe-text/textbuffer-view.c	Sun Mar  3 10:10:42 2002
@@ -194,7 +194,7 @@
 			continue;
 		}
 
-		if (xpos == view->width && sub != NULL &&
+		if (xpos >= view->width && sub != NULL &&
 		    (last_space <= indent_pos || last_space <= 10) &&
 		    view->longword_noindent) {
                         /* long word, remove the indentation from this line */
@@ -202,7 +202,7 @@
                         sub->indent = 0;
 		}
 
-		if (xpos == view->width) {
+		if (xpos >= view->width) {
 			xpos = indent_func == NULL ? indent_pos :
 				indent_func(view, line, -1);
 
@@ -233,12 +233,21 @@
 		if (view->utf8)
 			get_utf8_char(&ptr, 6);
 
-		xpos++;
-		if (*ptr++ == ' ') {
+		/* set line-wrap data with big5 charset */
+		xpos ++;
+		if (ptr[1] != '\0' && is_big5(ptr[0], ptr[1])) {
 			last_space = xpos-1;
+			xpos ++;
+			if (xpos < view->width)
+				ptr += 2;
 			last_space_ptr = ptr;
 			last_color = color;
-		}
+		} else if (*ptr == ' ') {
+			last_space = xpos-1;
+			last_space_ptr = ++ptr;
+			last_color = color;
+		} else
+			ptr++;
 	}
 
 	rec = g_malloc(sizeof(LINE_CACHE_REC)-sizeof(LINE_CACHE_SUB_REC) +
