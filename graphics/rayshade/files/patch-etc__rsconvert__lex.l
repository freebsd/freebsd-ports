--- etc/rsconvert/lex.l.orig	1992-02-10 12:03:54.000000000 +0900
+++ etc/rsconvert/lex.l	2013-05-28 22:55:24.000000000 +0900
@@ -22,6 +22,7 @@
 #include "libcommon/common.h"
 #include "y.tab.h"
 %}
+%option yylineno
 alpha	[a-zA-Z]
 special	[\.\_-]
 digit	[0-9]
@@ -113,7 +114,7 @@
 		if ((c = input()) == '/') {
 			WriteChar(c);
 			WriteNewline();
-			return;
+			return FALSE;
 		}
 		unput(c);
 	}
