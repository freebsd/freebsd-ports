--- src/calc/parser.y.orig	Thu Jun 21 11:34:14 2001
+++ src/calc/parser.y	Tue Jun 26 22:20:18 2001
@@ -148,12 +148,20 @@
   return 0;
 }
 
+int strgetc (const char **str) { 
+  char c; 
+  if ((c = **str)) { (*str)++; return c; }
+  return EOF;
+}
+
+void strungetc (int c, const char **str) { if (c != EOF) (*str)--; }
+ 
 int yylex (YYSTYPE *yylval, void *yyparam) {
   int c;
   parser_control *pc = (parser_control *) yyparam;
   
   /* Ignore whitespace, get first nonwhite character. */
-  while ((c = fgetc (pc->input)) == ' ' || c == '\t' || c == '\n');
+  while ((c = strgetc (&pc->input)) == ' ' || c == '\t' || c == '\n');
   
   /* End of input ? */
   if (c == EOF)
@@ -161,14 +169,16 @@
   
   /* Char starts a number => parse the number. */
   if (isdigit (c)) {
-    ungetc (c, pc->input);/* Put the char back. */
+    strungetc (c, &pc->input);	/* Put the char back. */
     {
       char *old_locale, *saved_locale;
+      int n;
 
       old_locale = setlocale (LC_ALL, NULL);
       saved_locale = g_strdup (old_locale);
       setlocale (LC_ALL, "C");
-      fscanf (pc->input, "%lf", &yylval->d_value);
+      sscanf (pc->input, "%lf%n", &yylval->d_value, &n);
+      pc->input += n;
       setlocale (LC_ALL, saved_locale);
       g_free (saved_locale);
     }
@@ -185,10 +195,10 @@
       sym_name = g_string_append_c (sym_name, c);
 
       /* Get another character. */
-      c = fgetc (pc->input);
+      c = strgetc (&pc->input);
     } while (c != EOF && isalnum (c));
     
-    ungetc (c, pc->input);
+    strungetc (c, &pc->input);
 
     yylval->s_value = sym_name->str;
     
@@ -264,11 +274,8 @@
      
 expression_t *expr_compile_string (const char* str, symbol_dict_t *dict) {
   parser_control pc;
-  FILE *stream;
 
-  stream = fmemopen (str, strlen (str), "r");
-
-  pc.input = stream;
+  pc.input = str;
   pc.expr = expr_new ();
   pc.dict = dict;
 
@@ -277,8 +284,6 @@
     expr_free (pc.expr);
     pc.expr = NULL;
   }
-
-  fclose (stream);
 
   return pc.expr;
 }
