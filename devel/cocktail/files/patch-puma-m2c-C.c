--- /usr/ports/devel/cocktail/work/cocktail-9309//./puma/m2c/C.c	Tue Feb 15 14:26:00 1994
+++ ./puma/m2c/C.c	Thu Aug  5 18:49:27 2004
@@ -1558,7 +1558,7 @@
           IO_WriteS(Tree_f, (STRING)"_Exit) () = yyExit;", 19L);
           IO_WriteNl(Tree_f);
           IO_WriteNl(Tree_f);
-          IO_WriteS(Tree_f, (STRING)"static FILE * yyf = stdout;", 27L);
+          IO_WriteS(Tree_f, (STRING)"static FILE * yyf;", 18L);
           IO_WriteNl(Tree_f);
           IO_WriteNl(Tree_f);
           IO_WriteS(Tree_f, (STRING)"static void yyAbort", 19L);
@@ -1594,6 +1594,8 @@
           IO_WriteS(Tree_f, (STRING)" ()", 3L);
           IO_WriteNl(Tree_f);
           IO_WriteS(Tree_f, (STRING)"{", 1L);
+          IO_WriteNl(Tree_f);
+          IO_WriteS(Tree_f, (STRING)"  yyf = stdout;", 15L);
           IO_WriteNl(Tree_f);
           WriteLine(W_35->Codes->U_1.V_12.Codes.BeginLine);
           Texts_WriteText(Tree_f, W_35->Codes->U_1.V_12.Codes.Begin);
