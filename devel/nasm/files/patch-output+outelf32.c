--- output/outelf32.c.orig
+++ output/outelf32.c
@@ -1702,7 +1702,7 @@
          * the source-file, the n_desc field should be set to the number
          * of remaining stabs
          */
-        WRITE_STAB(sptr, fileidx[0], 0, 0, 0, strlen(allfiles[0] + 12));
+        WRITE_STAB(sptr, fileidx[0], 0, 0, 0, stabstrlen);
 
         /* this is the stab for the main source file */
         WRITE_STAB(sptr, fileidx[mainfileindex], N_SO, 0, 0, 0);
