--- src/fe-text/gui-windows.c.orig	Mon Oct 29 20:51:52 2001
+++ src/fe-text/gui-windows.c	Tue Oct 30 01:48:09 2001
@@ -289,6 +289,7 @@
         unsigned char cmd;
 	char *ptr, *last_space_ptr;
 	int xpos, pos, indent_pos, last_space, last_color, color;
+	int w = 0;
 
 	g_return_val_if_fail(line->text != NULL, NULL);
 
@@ -343,14 +344,14 @@
 			continue;
 		}
 
-		if (xpos == COLS && sub != NULL &&
+		if (xpos >= COLS && sub != NULL &&
 		    (last_space <= indent_pos || last_space <= 10)) {
                         /* long word, remove the indentation from this line */
 			xpos -= sub->indent;
                         sub->indent = 0;
 		}
 
-		if (xpos == COLS) {
+		if (xpos >= COLS) {
 			xpos = indent_pos;
 
 			sub = g_new(LINE_CACHE_SUB_REC, 1);
@@ -376,8 +377,27 @@
 			continue;
 		}
 
-		xpos++;
-		if (*ptr++ == ' ') {
+		if(ptr[1] != '\0' && is_big5(ptr[0], ptr[1]))
+			w = 2;
+		else
+			w = 1;
+		
+		xpos+=w;
+		if (*ptr == ' ' ||
+		    (xpos <= COLS && w > 1)) {
+			last_space = xpos-1;
+			last_space_ptr = ptr + w;
+			last_color = color;
+		}
+		if(xpos <= COLS)
+			ptr += w;
+		else
+			ptr ++;
+		
+		if(w == 1 && xpos <= COLS &&
+			ptr[0] != '\0' && ptr[1] != '\0' &&
+			is_big5(ptr[0], ptr[1]))
+		{
 			last_space = xpos-1;
 			last_space_ptr = ptr;
 			last_color = color;
