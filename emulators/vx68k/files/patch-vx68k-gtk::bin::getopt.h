--- vx68k-gtk/bin/getopt.h.orig	Fri May 28 14:02:03 1999
+++ vx68k-gtk/bin/getopt.h	Wed Dec  1 18:24:18 2004
@@ -127,7 +127,7 @@
    `getopt'.  */
 
 #if defined __STDC__ && __STDC__
-# ifdef __GNU_LIBRARY__
+# if defined (__GNU_LIBRARY__) || defined (__FreeBSD__)
 /* Many other libraries have conflicting prototypes for getopt, with
    differences in the consts, in stdlib.h.  To avoid compilation
    errors, only prototype getopt for the GNU C library.  */
