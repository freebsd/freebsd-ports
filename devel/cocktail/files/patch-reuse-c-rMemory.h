--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/rMemory.h	Tue Feb 15 14:26:42 1994
+++ ./reuse/c/rMemory.h	Fri Sep 10 13:35:03 2004
@@ -31,15 +31,17 @@
 
 # ifdef __STDC__
 # define ARGS(parameters)	parameters
+# define NOARGS			void
 # else
 # define ARGS(parameters)	()
+# define NOARGS
 # endif
 
 extern unsigned long MemoryUsed	;
 			/* Holds the total amount of memory managed by	*/
 			/* this module.					*/
 
-extern void	InitrMemory	();
+extern void	InitrMemory	(NOARGS);
 			/* The memory module is initialized.		*/
 
 extern char *	Alloc		ARGS((register unsigned long ByteCount));
