--- out.c.orig
+++ out.c
@@ -1194,7 +1194,7 @@
 			    " seconds, %ld tries on line %d [251]", alts, outf_lnum);
 		    note(outbuf);
 		} else if (verbose) {
-		    fprintf(logf, "%s, %d/%d: Line breaker spent %ld tries\n",
+		    fprintf(p2c_logf, "%s, %d/%d: Line breaker spent %ld tries\n",
 			    infname, inf_lnum, outf_lnum, alts);
 		}
 		if (testinglinebreaker)
