--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/StringMem.h	Tue Feb 15 14:26:40 1994
+++ ./reuse/c/StringMem.h	Fri Sep 10 13:35:03 2004
@@ -32,12 +32,6 @@
 # include <stdio.h>
 # include "ratc.h"
 
-# ifdef __STDC__
-# define ARGS(parameters)	parameters
-# else
-# define ARGS(parameters)	()
-# endif
-
 typedef unsigned short * tStringRef;
 
 extern	tStringRef PutString	ARGS((register char * s, register cardinal length));
@@ -62,11 +56,11 @@
 			/* The string referenced by 'r' is printed on	*/
 			/* the file 'f'.				*/
 
-extern	void	WriteStringMemory ();
+extern	void	WriteStringMemory (NOARGS);
 			/* The contents of the string memory is printed	*/
 			/* on standard output.				*/
 
-extern	void	InitStringMemory ();
+extern	void	InitStringMemory (NOARGS);
 			/* The string memory is initialized.		*/
 
 # endif
