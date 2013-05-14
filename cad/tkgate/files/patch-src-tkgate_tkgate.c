--- src/tkgate/tkgate.c.orig	2013-05-14 15:24:54.000000000 +0200
+++ src/tkgate/tkgate.c	2013-05-14 15:25:15.000000000 +0200
@@ -1034,7 +1034,7 @@
    */
   r = Tk_Init(tcl);
   if (r == TCL_ERROR) {
-    fprintf(stderr,"Tk_Init Error in tkgate:\n%s\n",tcl->result);
+    fprintf(stderr,"Tk_Init Error in tkgate:\n%s\n",Tcl_GetStringResult(tcl));
     fprintf(stderr,"Perhaps you could try setting the environment variable TK_LIBRARY\n");
     fprintf(stderr,"to the directory in which tk init files can be found.  You can also\n");
     fprintf(stderr,"set TK_LIBRARY in options.h.\n");
