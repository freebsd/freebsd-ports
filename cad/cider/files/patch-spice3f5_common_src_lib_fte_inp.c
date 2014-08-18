--- spice3f5/common/src/lib/fte/inp.c.orig	1994-01-29 18:48:10 UTC
+++ spice3f5/common/src/lib/fte/inp.c
@@ -666,7 +666,7 @@ com_edit(wl)
 
     fprintf(cp_out, "run circuit? ");
     fflush(cp_out);
-    (void) gets(buf);
+    (void) fgets(buf,BSIZE_SP,stdin);
     if (buf[0] != 'n') {
       fprintf(cp_out, "running circuit\n");
       com_run(NULL);
