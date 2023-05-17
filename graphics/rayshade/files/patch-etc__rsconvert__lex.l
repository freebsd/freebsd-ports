--- etc/rsconvert/lex.l.orig	1992-02-10 03:03:54 UTC
+++ etc/rsconvert/lex.l
@@ -22,6 +22,7 @@
 #include "libcommon/common.h"
 #include "y.tab.h"
 %}
+%option yylineno
 alpha	[a-zA-Z]
 special	[\.\_-]
 digit	[0-9]
@@ -113,7 +114,7 @@ skipcomments()
 		if ((c = input()) == '/') {
 			WriteChar(c);
 			WriteNewline();
-			return;
+			return FALSE;
 		}
 		unput(c);
 	}
