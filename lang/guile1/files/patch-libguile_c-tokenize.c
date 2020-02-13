--- libguile/c-tokenize.c.orig	2010-12-13 19:24:04 UTC
+++ libguile/c-tokenize.c
@@ -898,13 +898,13 @@ case 3:
 /* rule 3 can match eol */
 YY_RULE_SETUP
 #line 71 "./c-tokenize.lex"
-{ OUT(eol); }
+{ /*OUT(eol);*/ }
 	YY_BREAK
 case 4:
 /* rule 4 can match eol */
 YY_RULE_SETUP
 #line 73 "./c-tokenize.lex"
-{ OUT(hash); IS_NOT_COOKIE; }
+{ /*OUT(hash);*/ IS_NOT_COOKIE; }
 	YY_BREAK
 case 5:
 YY_RULE_SETUP
