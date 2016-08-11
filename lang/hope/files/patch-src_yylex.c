--- src/yylex.c.orig	1999-04-09 12:21:08 UTC
+++ src/yylex.c
@@ -157,7 +157,7 @@ yylex(void)
 				inptr = start;
 				return ';';
 			}
-			if (! getline())
+			if (! get_line())
 				return EOF;
 		} else if (IsDigit(c)) {
 			/*
