--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Sets.h	Tue Feb 15 14:26:38 1994
+++ ./reuse/c/Sets.h	Fri Sep 10 13:35:03 2004
@@ -38,15 +38,9 @@
 # include "ratc.h"
 # include <stdio.h>
 
-# ifdef __STDC__
-# define ARGS(parameters)	parameters
-# else
-# define ARGS(parameters)	()
-# endif
-
-# define BitsPerBitset		32
-# define LdBitsPerBitset	5
-# define MaskBitsPerBitset	0x0000001f
+# define BitsPerBitset		(8*sizeof(long))
+# define LdBitsPerBitset	(BitsPerBitset==32?5:6)
+# define MaskBitsPerBitset	0x0000003f
 
 # define IsElement(Elmt, Set)	    ((long) ((Set)->BitsetPtr [(Elmt) >> LdBitsPerBitset] << ((Elmt) & MaskBitsPerBitset)) < 0)
 # define Size(Set)		    ((Set)->MaxElmt)
@@ -86,15 +80,15 @@
 /* extern bool	IsNotEqual	ARGS((tSet * Set1, tSet * Set2)); */
 /* extern bool	IsElement	ARGS((cardinal Elmt, tSet * Set)); */
 extern bool	IsEmpty		ARGS((tSet * Set));
-extern bool	Forall		ARGS((tSet * Set, bool (* Proc) ()));
-extern bool	Exists		ARGS((tSet * Set, bool (* Proc) ()));
-extern bool	Exists1		ARGS((tSet * Set, bool (* Proc) ()));
+extern bool	Forall		ARGS((tSet * Set, bool (* Proc) (cardinal c)));
+extern bool	Exists		ARGS((tSet * Set, bool (* Proc) (cardinal c)));
+extern bool	Exists1		ARGS((tSet * Set, bool (* Proc) (cardinal c)));
 extern void	Assign		ARGS((tSet * Set1, tSet * Set2));
 extern void	AssignElmt	ARGS((tSet * Set, cardinal Elmt));
 extern void	AssignEmpty	ARGS((tSet * Set));
-extern void	ForallDo	ARGS((tSet * Set, void (* Proc) ()));
+extern void	ForallDo	ARGS((tSet * Set, void (* Proc) (cardinal c)));
 extern void	ReadSet		ARGS((FILE * File, tSet * Set));
 extern void	WriteSet	ARGS((FILE * File, tSet * Set));
-extern void	InitSets	();
+extern void	InitSets	(NOARGS);
 
 # endif
