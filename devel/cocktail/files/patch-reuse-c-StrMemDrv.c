--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/StrMemDrv.c	Tue Feb 15 14:26:40 1994
+++ ./reuse/c/StrMemDrv.c	Fri Sep 10 13:35:03 2004
@@ -1,9 +1,12 @@
-static char rcsid [] = "$Id: StrMemDrv.c,v 1.4 1992/09/24 13:03:56 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: StrMemDrv.c,v 1.4 1992/09/24 13:03:56 grosch rel $");
 
 # include <stdio.h>
+# include <string.h>
+
 # include "StringMem.h"
 
-static void loop ()
+static void loop (void)
 {
    char string [256];
    tStringRef stringref;
@@ -19,7 +22,7 @@
    WriteStringMemory ();
 }
 
-main ()
+int main (void)
 {
    loop ();
    InitStringMemory ();
