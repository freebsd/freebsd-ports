--- src/misc/m.kappa/cmd/readin_data.c.orig	Sun Jul 11 17:29:10 2004
+++ src/misc/m.kappa/cmd/readin_data.c	Sun Jul 11 17:29:20 2004
@@ -10,7 +10,7 @@
   else
     if ((fd = fopen (input, "r")) == NULL) {
       fprintf (stderr, "ERROR: can't open <%s> to read in data\n", input);
-      exit();
+      exit(1);
     }
 
 /* read in data from the input file or stdin */
