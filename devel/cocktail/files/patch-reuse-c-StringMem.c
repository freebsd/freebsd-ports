--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/StringMem.c	Tue Feb 15 14:26:40 1994
+++ ./reuse/c/StringMem.c	Fri Sep 10 13:35:03 2004
@@ -47,7 +47,8 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Sept. 1987 */
 
-static char rcsid [] = "$Id: StringMem.c,v 1.13 1993/08/18 15:01:05 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: StringMem.c,v 1.13 1993/08/18 15:01:05 grosch rel $");
 
 # include "ratc.h"
 # include "StringMem.h"
@@ -81,7 +82,7 @@
 # endif
    {
       register char *	stringReg;
-      register long	NeededSpace	= (length + 3) & 0xfffffffe;
+      register unsigned long	NeededSpace	= (length + 3) & 0xfffffffe;
       register tStringRef StartPtr;
 
       if (MemorySpaceLeft < NeededSpace) {
@@ -163,7 +164,7 @@
 
 	 while (StringPtr < BlockPtr->Last) {
 	    long length = LengthSt (StringPtr) + 2;
-	    (void) printf ("%8x ", StringPtr);
+	    (void) printf ("%p ", (void*) StringPtr);
 	    WriteString (stdout, StringPtr);
 	    (void) fputc ('\n', stdout);
 	    if (length & 1) length ++;
