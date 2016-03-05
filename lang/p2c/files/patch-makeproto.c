--- makeproto.c.orig	1993-12-08 05:36:53 UTC
+++ makeproto.c
@@ -7,6 +7,7 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <time.h>
 
@@ -157,7 +158,7 @@ char **argv;
     char argdecls[MAXARGS][256], argnames[MAXARGS][80];
     char *cp, *cp2, *cp3;
     int i, j, pos, len, thistab, numstars, whichf, nargs, incomment, errors = 0;
-    long li;
+    time_t li;
     int typetab = 15, argtab = 30, width = 80, usenames = 0, usemacros = 0;
     int useextern = 0, staticness = -1, hasheader = 0, useifdefs = 0;
     int stupid = 1, firstdecl;
