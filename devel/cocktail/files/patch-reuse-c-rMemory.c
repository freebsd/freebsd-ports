--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/rMemory.c	Tue Feb 15 14:26:42 1994
+++ ./reuse/c/rMemory.c	Fri Sep 10 13:35:03 2004
@@ -49,14 +49,16 @@
  */
 
 /* Ich, Doktor Josef Grosch, Informatiker, Sept. 1987 */
-
-static char rcsid [] = "$Id: rMemory.c,v 1.14 1993/08/18 15:01:05 grosch rel $";
+# include <sys/cdefs.h>
+# include <sys/cdefs.h>
+__RCSID("$Id: rMemory.c,v 1.14 1993/08/18 15:01:05 grosch rel $");
 
 # include "ratc.h"
 # include "rMemory.h"
 # include "rSystem.h"
 # include "General.h"
 # include <stdio.h>
+# include <stdlib.h>
 
 # define MinSizeSmallBlock	4
 # define MaxSizeSmallBlock	62	/* 64 - 2	*/
@@ -75,6 +77,7 @@
 typedef cardinal	tSmallBlockRange;
 typedef cardinal	tLargeBlockRange;
 
+#ifndef FREEBSD
 static	tBlockPtr	SmallChain [MaxSizeSmallBlock    + 1] = { 0,
    NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL,
    NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL,
@@ -89,16 +92,21 @@
    NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL, NIL,
    NIL, NIL, NIL, NIL,
 };
+#endif
 static	char *		PoolFreePtr = 0;
 static	char *		PoolEndPtr  = 0;
 
 char * Alloc (ByteCount)
    register unsigned long ByteCount;
-
 /* Returns a pointer to dynamically allocated	*/
 /* space of size 'ByteCount' bytes.		*/
 
 {
+# ifdef FREEBSD
+   /* FreeBSD has an efficient memory allocator */  
+   /* The cocktail code assumes that allocated space is zeroed */
+   return (char*) calloc(1UL,ByteCount);
+#else
    ByteCount = (ByteCount + yyMaxAlign - 1) & yyAlignMasks [yyMaxAlign];
 
    if (ByteCount <= MaxSizeSmallBlock) {	/* handle small block */
@@ -187,6 +195,7 @@
 	 return (char *) CurrentBlock;
       }
    }
+#endif /*FREEBSD */
 }
 
 void Free (ByteCount, a)
@@ -198,6 +207,9 @@
 /* released.					*/
 
 {
+#ifdef FREEBSD
+   free(a);
+#else
    register tBlockPtr		BlockPtr;
    register tLargeBlockRange	ChainNumber;
 
@@ -214,10 +226,12 @@
       BlockPtr->Size		= ByteCount;
       LargeChain [ChainNumber]	= BlockPtr;
    }
+#endif /*FREEBSD */
 }
 
 void InitrMemory ()
 {
+#ifndef FREEBSD
    register int i;
 
    for (i = MinSizeSmallBlock; i <= MaxSizeSmallBlock; i += 2) {
@@ -226,6 +240,7 @@
    for (i = MinSizeLargeBlockLog; i <= MaxSizeLargeBlockLog; i ++) {
       LargeChain [i] = NIL;
    }
+#endif
    MemoryUsed	= 0;
    PoolFreePtr	= 0;
    PoolEndPtr	= 0;
