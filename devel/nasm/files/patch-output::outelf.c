--- output/outelf.c.orig	Sun Dec 14 16:25:34 2003
+++ output/outelf.c	Sun Dec 14 16:26:25 2003
@@ -1411,7 +1411,7 @@
      the source-file, the n_desc field should be set to the number
      of remaining stabs
   */
-  WRITE_STAB(sptr, fileidx[0], 0, 0, 0, strlen(allfiles[0]+12));
+  WRITE_STAB(sptr, fileidx[0], 0, 0, 0, stabstrlen);
 
   ptr=stabslines;
   numstabs = 0;
