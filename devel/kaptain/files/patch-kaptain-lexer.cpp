--- kaptain/lexer.cpp.orig	Wed Aug 14 14:25:07 2002
+++ kaptain/lexer.cpp	Fri Dec 20 16:14:31 2002
@@ -559,7 +559,7 @@
 int rarrow_lineno=0, larrow_lineno=0, 
   nonterminal_lineno=0, last_correct_lineno=0;
 char quoting, first_char; 
-bool exception(int e);
+bool myexception(int e);
 string safe_getenv(char *);
 #define DOUBLE_QUOTES 1
 #define SINGLE_QUOTES 2
@@ -921,7 +921,7 @@
 case 16:
 YY_RULE_SETUP
 #line 54 "lexer.lpp"
-{ if (exception(1)) return ERROR; }
+{ if (myexception(1)) return ERROR; }
 	YY_BREAK
 case 17:
 YY_RULE_SETUP
@@ -960,7 +960,7 @@
 case 23:
 YY_RULE_SETUP
 #line 67 "lexer.lpp"
-{ exception(1); return ERROR; }
+{ myexception(1); return ERROR; }
 	YY_BREAK
 case 24:
 YY_RULE_SETUP
@@ -990,7 +990,7 @@
 case 28:
 YY_RULE_SETUP
 #line 79 "lexer.lpp"
-{ exception(1); return ERROR; }
+{ myexception(1); return ERROR; }
 	YY_BREAK
 case 29:
 YY_RULE_SETUP
@@ -1037,7 +1037,7 @@
 case 34:
 YY_RULE_SETUP
 #line 101 "lexer.lpp"
-{ exception(1); return ERROR; }
+{ myexception(1); return ERROR; }
 	YY_BREAK
 case 35:
 *yy_cp = yy_hold_char; /* undo effects of setting up yytext */
@@ -1069,7 +1069,7 @@
 case 38:
 YY_RULE_SETUP
 #line 116 "lexer.lpp"
-{ exception(2); return ERROR; }
+{ myexception(2); return ERROR; }
 	YY_BREAK
 case 39:
 *yy_cp = yy_hold_char; /* undo effects of setting up yytext */
@@ -1115,12 +1115,12 @@
 case 43:
 YY_RULE_SETUP
 #line 141 "lexer.lpp"
-{ exception(3); return ERROR; }
+{ myexception(3); return ERROR; }
 	YY_BREAK
 case 44:
 YY_RULE_SETUP
 #line 142 "lexer.lpp"
-{ exception(3); return ERROR; }
+{ myexception(3); return ERROR; }
 	YY_BREAK
 case 45:
 YY_RULE_SETUP
@@ -1188,12 +1188,12 @@
 case 50:
 YY_RULE_SETUP
 #line 186 "lexer.lpp"
-{ exception(4); return ERROR; }
+{ myexception(4); return ERROR; }
 	YY_BREAK
 case 51:
 YY_RULE_SETUP
 #line 187 "lexer.lpp"
-{ exception(4); return ERROR; }
+{ myexception(4); return ERROR; }
 	YY_BREAK
 case 52:
 YY_RULE_SETUP
@@ -2142,7 +2142,7 @@
 extern Grammar * yygrammar;
 
 
-bool exception(int e)
+bool myexception(int e)
 {
   ostringstream message;
   string s;
