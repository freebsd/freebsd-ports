--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Strings.c	Tue Feb 15 14:27:02 1994
+++ ./reuse/m2c/Strings.c	Thu Aug  5 18:49:34 2004
@@ -22,7 +22,7 @@
 static struct S_1 {
     CHAR A[15 + 1];
 } MyCHR;
-static void Error ARGS(());
+static void Error  ARGS((NOARGS));
 static CARDINAL Rank ARGS((CHAR ch));
 #define MaxInt	2147483647
 #define MaxIntDiv10	(MaxInt / 10)
