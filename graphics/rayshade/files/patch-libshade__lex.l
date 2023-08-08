--- libshade/lex.l.orig	1992-02-10 03:04:02 UTC
+++ libshade/lex.l
@@ -29,6 +29,7 @@
 #include "y.tab.h"
 extern char *strsave();
 %}
+%option yylineno
 alpha	[a-zA-Z]
 special	[\.\_-]
 digit	[0-9]
@@ -171,7 +172,7 @@ skipcomments()
 		while (input() != '*')
 			;
 		if ((c = input()) == '/')
-			return;
+			return FALSE;
 		unput(c);
 	}
 }
