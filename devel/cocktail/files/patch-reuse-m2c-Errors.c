--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Errors.c	Tue Feb 15 14:26:50 1994
+++ ./reuse/m2c/Errors.c	Thu Aug  5 18:49:33 2004
@@ -107,7 +107,7 @@
 static void StoreMessage ARGS((BOOLEAN pIsErrorCode, CARDINAL pErrorCode, CARDINAL pErrorClass, Positions_tPosition pPosition, CARDINAL pInfoClass, ADDRESS pInfo));
 static BOOLEAN IsLess ARGS((INTEGER i, INTEGER j));
 static void Swap ARGS((INTEGER i, INTEGER j));
-static void yyExit ARGS(());
+static void yyExit  ARGS((NOARGS));
 
 void Errors_ErrorMessage
 # ifdef __STDC__
@@ -365,7 +365,7 @@
 # endif
 {
   INTEGER i;
-  ADDRESS Info;
+  ADDRESS Info = 0;
   Strings_tString s;
 
   Sort_Sort(1L, MessageCount, (Sort_tProcIntIntBool)IsLess, (Sort_tProcIntInt)Swap);
