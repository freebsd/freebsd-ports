--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Errors.h	Tue Feb 15 14:26:35 1994
+++ ./reuse/c/Errors.h	Fri Sep 10 13:35:02 2004
@@ -44,13 +44,7 @@
 # define xxSet			8
 # define xxIdent		9
 
-# if defined __STDC__ | defined __cplusplus
-# define ARGS(parameters)	parameters
-# else
-# define ARGS(parameters)	()
-# endif
-
-extern void (* Errors_Exit) ();
+extern void (* Errors_Exit) (NOARGS);
 			/* Refers to a procedure that specifies		*/
 			/* what to do if 'ErrorClass' = Fatal.		*/
 			/* Default: terminate program execution.	*/
