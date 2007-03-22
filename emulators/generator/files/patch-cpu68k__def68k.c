--- cpu68k/def68k.c.orig	Sun May  4 21:58:27 2003
+++ cpu68k/def68k.c	Thu Mar 22 00:58:30 2007
@@ -21,7 +21,7 @@
 /* file-scope global variables */
 
 static int total = 0;
-static int clocks_movetable[]; /* pre-declaration */
+int clocks_movetable[]; /* pre-declaration */
 
 /* private functions for forward references */
 
