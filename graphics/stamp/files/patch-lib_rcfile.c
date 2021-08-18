--- lib/rcfile.c.orig	1999-03-11 08:30:32 UTC
+++ lib/rcfile.c
@@ -101,8 +101,8 @@ if ((!(strcmp(Args->LowerFont,""))) &&
     exit(ERR_NOLFONT) ;
   }
 
-  if ((!(strcmp(Args->Infile,""))) ||
-      (!(strcmp(Args->Outfile,"")))) {
+  if ((Args->Infile == NULL) ||
+      (Args->Outfile == NULL)) {
     fprintf(stderr, "stamp: You must specify both an input and output JPEG image.\n") ;
     exit(ERR_MISSIOFILE) ;
   }
