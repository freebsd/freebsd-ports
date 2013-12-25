--- libshade/lex.l.orig	1992-02-10 12:04:02.000000000 +0900
+++ libshade/lex.l	2013-05-28 22:45:54.000000000 +0900
@@ -29,6 +29,7 @@
 #include "y.tab.h"
 extern char *strsave();
 %}
+%option yylineno
 alpha	[a-zA-Z]
 special	[\.\_-]
 digit	[0-9]
@@ -171,7 +172,7 @@
 		while (input() != '*')
 			;
 		if ((c = input()) == '/')
-			return;
+			return FALSE;
 		unput(c);
 	}
 }
