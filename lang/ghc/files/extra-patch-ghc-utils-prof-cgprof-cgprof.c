--- ghc/utils/prof/cgprof/cgprof.c.orig	Thu Dec 11 11:50:34 2003
+++ ghc/utils/prof/cgprof/cgprof.c	Thu Dec 11 11:51:47 2003
@@ -1,5 +1,5 @@
 /* ------------------------------------------------------------------------
- * $Id: cgprof.c,v 1.1 2000/04/05 10:06:36 simonmar Exp $
+ * $Id: cgprof.c,v 1.2 2002/10/05 22:18:46 panne Exp $
  *									
  *	Copyright (C) 1995-2000 University of Oxford
  *									
@@ -1183,8 +1183,8 @@
   } /* end of new for loop */
 
   *nonodes = symbol_table_next;
-  fprintf(log,"%s: read %d lines from profile.Graph contains %i nodes. 
-          \n",Pgm,nolines,symbol_table_next);
+  fprintf(log,"%s: read %d lines from profile.Graph contains %i nodes.\n",
+          Pgm,nolines,symbol_table_next);
 
   free_cc_matrix(cc_m); /* be nice and clean up the cost centre matrix */
 }
