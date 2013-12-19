--- trans.h.orig
+++ trans.h
@@ -1773,7 +1773,7 @@
 
 extern char *infname, *outfname, *codefname, *hdrfname;
 extern char *requested_module;
-extern FILE *inf, *outf, *codef, *hdrf, *logf;
+extern FILE *inf, *outf, *codef, *hdrf, *p2c_logf;
 extern short setup_complete, found_module;
 extern short regression, verbose, conserve_mem;
 extern int inf_lnum, inf_ltotal;
@@ -1861,8 +1861,10 @@
 
 /* Our library omits declarations for these functions! */
 
+#ifndef __FreeBSD__
 int link           PP( (char *, char *) );
 int unlink         PP( (char *) );
+#endif
 
 
 
