--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/rSystem.h	Tue Feb 15 14:26:43 1994
+++ ./reuse/c/rSystem.h	Fri Sep 10 13:35:03 2004
@@ -10,8 +10,10 @@
 
 # ifdef __STDC__
 # define ARGS(parameters)	parameters
+# define NOARGS			void
 # else
 # define ARGS(parameters)	()
+# define NOARGS	
 # endif
 
 /* interface for machine dependencies */
@@ -59,10 +61,10 @@
 			/* memory space of size 'ByteCount' bytes.	*/
 			/* Returns NIL if space is exhausted.		*/
 
-extern long	rTime		();
+extern long	rTime		(NOARGS);
 			/* Returns consumed cpu-time in milliseconds.	*/
 
-extern int	GetArgCount	();
+extern int	GetArgCount	(NOARGS);
 			/* Returns number of arguments.			*/
 
 extern void	GetArgument	ARGS((int ArgNum, char * Argument));
@@ -73,7 +75,7 @@
 			/* Dummy procedure that passes the values	*/
 			/* 'argc' and 'argv' from Modula-2 to C.	*/
 
-extern int	rErrNo		();
+extern int	rErrNo		(NOARGS);
 			/* Returns the current system error code.	*/
 
 extern int	rSystem		ARGS((char * String));
@@ -85,7 +87,7 @@
 			/* Terminates program execution and passes the	*/
 			/* value 'Status' to the operating system.	*/
 
-extern void	BEGIN_System	();
+extern void	BEGIN_rSystem	(NOARGS);
 			/* Dummy procedure with empty body.		*/
 
 # endif
