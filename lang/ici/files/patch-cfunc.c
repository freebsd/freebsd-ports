--- cfunc.c	Mon Jan 26 10:37:06 2004
+++ cfunc.c	Mon Jan 26 10:41:23 2004
@@ -1378,7 +1378,7 @@
     register char       *p;
     register int        i;              /* Where we are up to in buf. */
     register int        j;
-    int                 which;
+    long                which;
     int                 nargs;
     char                subfmt[40];     /* %...? portion of string. */
     int                 stars[2];       /* Precision and field widths. */
@@ -1395,7 +1395,7 @@
 #define IPLUSEQ         i +=
 #endif
 
-    which = (int)CF_ARG1(); /* sprintf, printf, fprintf */
+    which = (long)CF_ARG1(); /* sprintf, printf, fprintf */
     if (which != 0 && NARGS() > 0 && isfile(ARG(0)))
     {
         which = 2;
