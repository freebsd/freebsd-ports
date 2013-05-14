--- src/tkgate/main.c.orig	2013-05-14 15:23:12.000000000 +0200
+++ src/tkgate/main.c	2013-05-14 15:23:30.000000000 +0200
@@ -38,7 +38,7 @@
 
   r = Tcl_Init(tcl);
   if (r == TCL_ERROR) {
-    fprintf(stderr,"Tcl_Init Error in tkgate:\n%s\n",tcl->result);
+    fprintf(stderr,"Tcl_Init Error in tkgate:\n%s\n",Tcl_GetStringResult(tcl));
     fprintf(stderr,"Perhaps you could try setting the environment variable TCL_LIBRARY\n");
     fprintf(stderr,"to the directory in which init.tcl can be found.  You can also\n");
     fprintf(stderr,"set TCL_LIBRARY in options.h.\n");
