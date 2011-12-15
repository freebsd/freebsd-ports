--- ./src/ctran.c.orig	1998-08-28 19:01:57.000000000 +0200
+++ ./src/ctran.c	2011-12-15 18:06:56.000000000 +0100
@@ -7,6 +7,9 @@
 ----------------------------------------------------------------*/
 /*{{{  global decls*/
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
 #define  BUFLEN			1000	/* max len of ID or keyword in i/p */
 #define  PROTECT_LINE_CHAR	'@'	/* replaces some "#include's */
 
@@ -762,11 +765,11 @@
 	int    lineno = 0,  max_val = 0,  val;
 
 	if ( !(dict_file = fopen (dict_filename, "r")) )
-		return;
+		return 0;
 
 	if ( ! fgets (buf, BUFLEN, dict_file) ) {
 		fclose (dict_file);
-		return;
+		return 0;
 	}
 
 	/*{{{  1st line may give 'next_val' (otherwise its a normal line)*/
@@ -928,7 +931,7 @@
 	}
 
 	fclose (dict_file);
-	return;
+	return 0;
 }
 /*}}}*/
 /*{{{  write_new_dict ()*/
@@ -1110,7 +1113,7 @@
 			while ((c = getc (ip_file)) != delim) {
 				switch (c) {
 				case  EOF :
-					return;
+					return 0;
 			
 				case  '\\' :
 					/*---------------------------------------*/
@@ -1118,7 +1121,7 @@
 					/*---------------------------------------*/
 					c = getc (ip_file);
 					if (c == EOF)
-						return;
+						return 0;
 					break;
 				}
 			}
@@ -1208,7 +1211,7 @@
 					c = getc (ip_file);
 			
 				if (c == EOF)
-					return;
+					return 0;
 			
 				last_token_type  &=  ~TK_SPACE;		/* unset TK_SPACE, if set */
 				op_linelen = 0;
@@ -1380,7 +1383,7 @@
 			while ((c = getc (ip_file)) != delim) {
 				switch (c) {
 				case  EOF :
-					return;
+					return 0;
 			
 				case  '\\' :
 					/*---------------------------------------*/
@@ -1388,7 +1391,7 @@
 					/*---------------------------------------*/
 					write_and_get_next_char (c);
 					if (c == EOF)
-						return;
+						return 0;
 					writechar (c);
 					break;
 			
@@ -1571,14 +1574,14 @@
 	/*------------------------------------------------------*/
 	for (sp = keytab [hashval];  sp;  sp = sp->next)
 		if (! strcmp (sp->word, word))
-			return;		/* found! */
+			return 0;		/* found! */
 
 	/*------------------------------------------------------*/
 	/* Now search for it in the symbol table, 'symtab'.	*/
 	/*------------------------------------------------------*/
 	for (sp = symtab [hashval];  sp;  sp = sp->next)
 		if (! strcmp (sp->word, word))
-			return;		/* found! */
+			return 0;		/* found! */
 
 	/*------------------------------------------------------*/
 	/* Not found in either table  (i.e. not a keyword and	*/
@@ -1609,7 +1612,7 @@
 	sp->next = symtab [hashval];  /* add to front of list */
 	symtab [hashval] = sp;
 
-	return;
+	return 0;
 }
 
 /*}}}*/
