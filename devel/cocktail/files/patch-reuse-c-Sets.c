--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Sets.c	Tue Feb 15 14:26:38 1994
+++ ./reuse/c/Sets.c	Fri Sep 10 13:35:03 2004
@@ -44,7 +44,11 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Sept. 1987 */
 
-static char rcsid [] = "$Id: Sets.c,v 1.12 1993/08/20 08:12:15 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: Sets.c,v 1.12 1993/08/20 08:12:15 grosch rel $");
+
+# include <stdlib.h>
+# include <stdio.h>
 
 # include "ratc.h"
 # include "Sets.h"
@@ -306,7 +310,7 @@
     
 bool Forall (Set, Proc)
    tSet *	Set	;
-   bool		(* Proc) ();
+   bool		(* Proc) (cardinal c);
    {
       register tSet *	rSet	= Set;
       register cardinal	i;
@@ -320,7 +324,7 @@
     
 bool Exists (Set, Proc)
    tSet *	Set	;
-   bool		(* Proc) ();
+   bool		(* Proc) (cardinal c);
    {
       register tSet *	rSet	= Set;
       register cardinal	i;
@@ -334,7 +338,7 @@
     
 bool Exists1 (Set, Proc)
    tSet *	Set	;
-   bool		(* Proc) ();
+   bool		(* Proc) (cardinal c);
    {
       register tSet *	rSet	= Set;
       register cardinal	i, n;
@@ -397,7 +401,7 @@
 
 void ForallDo (Set, Proc)
    tSet *	Set	;
-   void		(* Proc) ();
+   void		(* Proc) (cardinal c);
    {
       register tSet *	rSet	= Set;
       register cardinal	i;
@@ -428,8 +432,7 @@
 
 static FILE * g;
 
-void PrintElmt (Elmt)
-   cardinal	Elmt	;
+static void PrintElmt (cardinal Elmt)
    {
       (void) fprintf (g, " %d", Elmt);
    }
@@ -447,5 +450,5 @@
 void InitSets ()
    {
       if (sizeof (BITSET) != BytesPerBitset)
-	 (void) fprintf (stderr, "Sets: sizeof (BITSET) = %d\n", sizeof (BITSET));
+	 (void) fprintf (stderr, "Sets: sizeof (BITSET) = %d\n", (int)sizeof (BITSET));
    }
