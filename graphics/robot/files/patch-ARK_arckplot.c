--- ARK/arkcplot.c.orig	2009-04-11 21:58:56.000000000 +0200
+++ ARK/arkcplot.c	2009-04-11 22:00:06.000000000 +0200
@@ -3472,7 +3472,7 @@
  * no point in plotting blanks */
 
 	length = MIN( *n, non_z_length(text));
-	text[length] = (char) NULL;
+	text[length] = 0;
 /* find length of string */
 /*	XQueryTextExtents(dpy, cur_font->fid, text, length,
 		&direction, &ascent, &descent, &overall); */
@@ -3519,7 +3519,7 @@
  * no point in plotting blanks */
 
 	length = MIN( *n, non_z_length(text));
-	text[length] = (char) NULL;
+	text[length] = 0;
 /* find length of string */
 /*	XQueryTextExtents(dpy, cur_font->fid, text, length,
 		&direction, &ascent, &descent, &overall); */
@@ -4376,7 +4376,7 @@
 symbol_size symbol_size rlineto\n\
 symbol_size neg_symbol_size rlineto\n\
 neg_symbol_size neg_symbol_size rlineto\n\
-neg_symbol_size symbol_size rlineto\n\ 
+neg_symbol_size symbol_size rlineto\n\
 stroke\n} bind def\n"); 
 
 fprintf(fp,
@@ -5431,7 +5431,7 @@
 	slen = strlen(text);
 	for (i = 0; i < slen; i++){
 		if(text[i] == ']'){
-			text[i] = (char) NULL;
+			text[i] = 0;
 			break;
 		}
 	}
@@ -5905,7 +5905,7 @@
 	slen = strlen(text);
 	for (i = 0; i < slen; i++){
 		if(text[i] == '}'){
-			text[i] = (char) NULL;
+			text[i] = 0;
 			break;
 		}
 	}
@@ -6090,7 +6090,7 @@
 char	buff[2];
 
 	strncpy(buff, ch, 1);
-	buff[1] = (char) NULL;
+	buff[1] = 0;
 
 	if(cur_font == NULL){
 		printf("Robot ERROR: NULL font in chchk!!\n");
