--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Idents.h	Tue Feb 15 14:26:36 1994
+++ ./reuse/c/Idents.h	Fri Sep 10 13:35:03 2004
@@ -39,12 +39,6 @@
 # include "ratc.h"
 # include "StringMem.h"
 
-# ifdef __STDC__
-# define ARGS(parameters)	parameters
-# else
-# define ARGS(parameters)	()
-# endif
-
 typedef cardinal	tIdent;
 
 extern	tIdent	NoIdent; /* A default identifer (empty string)		*/
@@ -60,20 +54,20 @@
 			/* Returns a reference to the string identified	*/
 			/* by 'ident'.					*/
 
-extern	tIdent	MaxIdent	();
+extern	tIdent	MaxIdent	(NOARGS);
 			/* Returns the currently maximal identifier.	*/
 
 extern	void	WriteIdent	ARGS((FILE * file, tIdent ident));
 			/* The string encoded by the identifier 'ident'	*/
 			/* is printed on the file.			*/
 
-extern	void	WriteIdents	();
+extern	void	WriteIdents	(NOARGS);
 			/* The contents of the identifier table is	*/
 			/* printed on the standard output.		*/
 
-extern	void	InitIdents	();
+extern	void	InitIdents	(NOARGS);
 			/* The identifier table is initialized.		*/
 
-extern	void	WriteHashTable	();
+extern	void	WriteHashTable	(NOARGS);
 
 # endif
