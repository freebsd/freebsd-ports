--- lex.c.orig
+++ lex.c
@@ -520,7 +520,7 @@
 	    if (outf != stdout)
 		printf("Translation aborted: Too many errors.\n");
 	    if (verbose)
-		fprintf(logf, "Translation aborted: Too many errors.\n");
+		fprintf(p2c_logf, "Translation aborted: Too many errors.\n");
 	    closelogfile();
 	    exit_failure();
 	}
@@ -541,9 +541,9 @@
         printf("Translation aborted.\n");
     }
     if (verbose) {
-	fprintf(logf, "%s:%d:%d: %s\n",
+	fprintf(p2c_logf, "%s:%d:%d: %s\n",
 		infname, inf_lnum, outf_lnum, msg);
-	fprintf(logf, "Translation aborted.\n");
+	fprintf(p2c_logf, "Translation aborted.\n");
     }
     closelogfile();
     exit_failure();
@@ -562,7 +562,7 @@
 {
     if (checkeatnote(msg)) {
 	if (verbose)
-	    fprintf(logf, "%s:%d:%d: Omitted warning: %s\n",
+	    fprintf(p2c_logf, "%s:%d:%d: Omitted warning: %s\n",
 		    infname, inf_lnum, outf_lnum, msg);
 	return;
     }
@@ -577,7 +577,7 @@
 {
     if (checkeatnote(msg)) {
 	if (verbose)
-	    fprintf(logf, "%s:%d:%d: Omitted internal error in %s: %s\n",
+	    fprintf(p2c_logf, "%s:%d:%d: Omitted internal error in %s: %s\n",
 		    infname, inf_lnum, outf_lnum, proc, msg);
 	return;
     }
@@ -596,7 +596,7 @@
 {
     if (blockkind == TOK_IMPORT || checkeatnote(msg)) {
 	if (verbose)
-	    fprintf(logf, "%s:%d:%d: Omitted note: %s\n",
+	    fprintf(p2c_logf, "%s:%d:%d: Omitted note: %s\n",
 		    infname, inf_lnum, outf_lnum, msg);
 	return;
     }
@@ -612,12 +612,12 @@
 {
     if (blockkind == TOK_IMPORT || checkeatnote(msg)) {
 	if (verbose)
-	    fprintf(logf, "%s:%d:%d: Omitted end-note: %s\n",
+	    fprintf(p2c_logf, "%s:%d:%d: Omitted end-note: %s\n",
 		    infname, inf_lnum, outf_lnum, msg);
 	return;
     }
     if (verbose)
-	fprintf(logf, "%s:%d:%d: Recorded end-note: %s\n",
+	fprintf(p2c_logf, "%s:%d:%d: Recorded end-note: %s\n",
 		infname, inf_lnum, outf_lnum, msg);
     (void) strlist_add(&endnotelist, msg);
 }
@@ -1327,7 +1327,7 @@
 	    else
 		printf("Reading include file \"%s\"\n", fn);
 	if (verbose)
-	    fprintf(logf, "Reading include file \"%s\"\n", fn);
+	    fprintf(p2c_logf, "Reading include file \"%s\"\n", fn);
         if (expandincludes == 0) {
             push_input_file(fp, fn, 2);
             curtok = TOK_INCLUDE;
