--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/General.h	Tue Feb 15 14:26:36 1994
+++ ./reuse/c/General.h	Fri Sep 10 13:35:03 2004
@@ -30,8 +30,10 @@
 
 # ifdef __STDC__
 # define ARGS(parameters)	parameters
+# define NOARGS			void
 # else
 # define ARGS(parameters)	()
+# define NOARGS
 # endif
 
 # define Min(a,b) ((a <= b) ? a : b)
@@ -44,7 +46,7 @@
 extern unsigned long	Exp2 ARGS((register cardinal x));
 			/* Returns 2 to the power of 'x'.		*/
 
-extern short	yyMaxAlign;
+extern unsigned long	yyMaxAlign;
 extern long	yyAlignMasks [];
 
 # endif
