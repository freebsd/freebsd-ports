--- lib/rcfile.c.orig	Fri Dec 24 15:02:25 1999
+++ lib/rcfile.c	Fri Dec 24 15:06:09 1999
@@ -101,8 +101,8 @@
     exit(ERR_NOLFONT) ;
   }
 
-  if ((!(strcmp(Args->Infile,""))) ||
-      (!(strcmp(Args->Outfile,"")))) {
+  if ((Args->Infile == NULL) ||
+      (Args->Outfile == NULL)) {
     fprintf(stderr, "stamp: You must specify both an input and output JPEG image.\n") ;
     exit(ERR_MISSIOFILE) ;
   }
