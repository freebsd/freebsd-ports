--- comment.c.orig
+++ comment.c
@@ -299,7 +299,7 @@
 	    printf("\"%s\", line %d,%d: %s\n", infname, inf_lnum, outf_lnum, msg);
     }
     if (verbose)
-	fprintf(logf, "%s:%d:%d: %s\n", infname, inf_lnum, outf_lnum, msg);
+	fprintf(p2c_logf, "%s:%d:%d: %s\n", infname, inf_lnum, outf_lnum, msg);
     if (notephase == 2 || regression)
 	prefix = format_s("\004 p2c: %s:", infname);
     else
