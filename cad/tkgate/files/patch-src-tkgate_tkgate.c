--- src/tkgate/tkgate.c.orig	2009-03-18 10:23:18.000000000 +0100
+++ src/tkgate/tkgate.c	2013-05-14 16:31:17.000000000 +0200
@@ -1034,7 +1034,7 @@
    */
   r = Tk_Init(tcl);
   if (r == TCL_ERROR) {
-    fprintf(stderr,"Tk_Init Error in tkgate:\n%s\n",tcl->result);
+    fprintf(stderr,"Tk_Init Error in tkgate:\n%s\n",Tcl_GetStringResult(tcl));
     fprintf(stderr,"Perhaps you could try setting the environment variable TK_LIBRARY\n");
     fprintf(stderr,"to the directory in which tk init files can be found.  You can also\n");
     fprintf(stderr,"set TK_LIBRARY in options.h.\n");
@@ -1097,6 +1097,7 @@
  *****************************************************************************/
 int Tkgate_Init(Tcl_Interp *tcl)
 {
+  Tk_Init(tcl);
   Tcl_CreateCommand(tcl,"tkgate_main",tkgate_main,0,0);
   Tcl_CreateCommand(tcl,"tkgate_starttk",tkgate_starttk,0,0);
   Tcl_CreateCommand(tcl,"tkgate_posttk",tkgate_posttk,0,0);
