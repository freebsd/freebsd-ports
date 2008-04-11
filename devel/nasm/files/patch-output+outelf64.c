--- output/outelf64.c.orig	2008-03-03 16:15:57.373145096 -0500
+++ output/outelf64.c	2008-03-03 16:23:30.075070061 -0500
@@ -1841,7 +1841,7 @@
         the source-file, the n_desc field should be set to the number
         of remaining stabs
         */
-        WRITE_STAB(sptr, fileidx[0], 0, 0, 0, strlen(allfiles[0] + 12));
+        WRITE_STAB(sptr, fileidx[0], 0, 0, 0, stabstrlen);
 
         /* this is the stab for the main source file */
         WRITE_STAB(sptr, fileidx[mainfileindex], N_SO, 0, 0, 0);
