--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/rSystem.c	Tue Feb 15 14:26:46 1994
+++ ./reuse/m2c/rSystem.c	Thu Aug  5 18:49:33 2004
@@ -10,10 +10,17 @@
 /* compilation with the option -DUNIX uses UNIX system calls for IO (efficient),
    otherwise the C library routines are used for IO (portable).			*/
 
+# include <sys/types.h>
+# include <sys/uio.h>
+# include <unistd.h>
+# include <stdlib.h>
+
 # ifdef __STDC__
 # define ARGS(parameters)	parameters
+# define NOARGS			void
 # else
 # define ARGS(parameters)	()
+# define NOARGS			
 # endif
 
 # ifndef bool
@@ -22,9 +29,9 @@
 # define tFile int
 
 # ifdef m68000
-# define hz 50
+# define HZ 50
 # else
-# define hz 60
+# define HZ 60
 # endif
 
 /* binary IO */
@@ -65,10 +72,10 @@
 			/* memory space of size 'ByteCount' bytes.	*/
 			/* Returns NIL if space is exhausted.		*/
 
-extern long	rTime		();
+extern long	rTime		(NOARGS);
 			/* Returns consumed cpu-time in milliseconds.	*/
 
-extern int	GetArgCount	();
+extern int	GetArgCount	(NOARGS);
 			/* Returns number of arguments.			*/
 
 extern void	GetArgument	ARGS((int ArgNum, char * Argument));
@@ -79,7 +86,7 @@
 			/* Dummy procedure that passes the values	*/
 			/* 'argc' and 'argv' from Modula-2 to C.	*/
 
-extern int	rErrNo		();
+extern int	rErrNo		(NOARGS);
 			/* Returns the current system error code.	*/
 
 extern int	rSystem		ARGS((char * String));
@@ -91,7 +98,7 @@
 			/* Terminates program execution and passes the	*/
 			/* value 'Status' to the operating system.	*/
 
-extern void	BEGIN_System	();
+extern void	BEGIN_rSystem	(NOARGS);
 			/* Dummy procedure with empty body.		*/
 
 
@@ -216,9 +223,10 @@
 
 /* calls other than IO */
 
-/* # include <malloc.h> */
-
-char * rAlloc (ByteCount) long ByteCount; { return (char *) malloc ((unsigned) ByteCount); }
+char * rAlloc (ByteCount) long ByteCount; 
+{ 
+    return (char *) calloc (1L, (unsigned) ByteCount); 
+}
 
 # include <sys/times.h>
 
@@ -229,7 +237,7 @@
 # else
    struct tms	buffer;
    (void) times (& buffer);
-   return (buffer.tms_utime + buffer.tms_stime) * 1000 / hz;
+   return (buffer.tms_utime + buffer.tms_stime) * 1000 / HZ;
 # endif
 }
 
@@ -264,8 +272,6 @@
 
 int rSystem (String) char * String; { return system (String); }
 
-extern void exit ();
-
 void rExit (Status) int Status; { exit (Status); }
 
-void BEGIN_rSystem () {}
+void BEGIN_rSystem (NOARGS) {}
