--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Idents.c	Tue Feb 15 14:26:36 1994
+++ ./reuse/c/Idents.c	Fri Sep 10 13:35:03 2004
@@ -44,7 +44,8 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Sept. 1987 */
 
-static char rcsid [] = "$Id: Idents.c,v 1.12 1992/05/05 13:19:05 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: Idents.c,v 1.12 1992/05/05 13:19:05 grosch rel $");
 
 # include "ratc.h"
 # include "Idents.h"
@@ -65,7 +66,7 @@
 static	unsigned short	Null		= 0;
 static	IdentTableEntry	Table [InitialTableSize] = {{0, 0, 0}, {& Null, 0, cNoIdent}};
 static	IdentTableEntry	* TablePtr	= Table;
-static	unsigned long	IdentTableSize	= InitialTableSize;
+static	tIdent	IdentTableSize	= InitialTableSize;
 static	tIdent		IdentCount	= 1;
 
 static	tIdent		HashTable [HashTableSize] = {
@@ -105,7 +106,7 @@
 
 tIdent MakeIdent
 # ifdef __STDC__
-   (register char * string, register cardinal length)
+   (char * string, cardinal length)
 # else
    (string, length)
    register char *	string;
@@ -129,7 +130,7 @@
       }
 
       if (++ IdentCount == IdentTableSize)	/* not found: enter */
-	 ExtendArray ((char * *) & TablePtr, & IdentTableSize, (long) sizeof (IdentTableEntry));
+	 ExtendArray ((char * *) & TablePtr, (unsigned long*)&IdentTableSize, (long) sizeof (IdentTableEntry));
       TablePtrReg = & TablePtr [IdentCount];
       TablePtrReg->String	= PutString (string, length);
       TablePtrReg->Length	= length;
