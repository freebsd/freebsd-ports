--- parse.c.orig
+++ parse.c
@@ -4392,7 +4392,7 @@
     long saveserial;
 
     if (verbose)
-	fprintf(logf, "%s, %d/%d: Translating %s (in %s)\n",
+	fprintf(p2c_logf, "%s, %d/%d: Translating %s (in %s)\n",
 		infname, inf_lnum, outf_lnum,
 		curctx->name, curctx->ctx->name);
     notephase = 1;
@@ -5477,8 +5477,8 @@
     if (!fp) {
         if (need)
             perror(infnbuf);
-	if (logf)
-	    fprintf(logf, "(Unable to open search file \"%s\")\n", infnbuf);
+	if (p2c_logf)
+	    fprintf(p2c_logf, "(Unable to open search file \"%s\")\n", infnbuf);
         return 0;
     }
     flushcomments(NULL, -1, -1);
@@ -5515,7 +5515,7 @@
 	    else
 		printf("Reading import text for \"%s\"\n", mod->name);
 	if (verbose)
-	    fprintf(logf, "%s, %d/%d: Reading import text for \"%s\"\n",
+	    fprintf(p2c_logf, "%s, %d/%d: Reading import text for \"%s\"\n",
 		    infname, inf_lnum, outf_lnum, mod->name);
         pushctx(mod);
         gettok();
