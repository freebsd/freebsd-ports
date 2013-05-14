--- src/tkgate/scopewin.c.orig	2013-05-14 14:46:53.000000000 +0200
+++ src/tkgate/scopewin.c	2013-05-14 14:47:30.000000000 +0200
@@ -469,7 +469,7 @@
     return TCL_ERROR;
   }
 
-  tcl->result = Tk_PathName(w);
+  Tcl_SetResult(tcl, Tk_PathName(w), TCL_STATIC);
 
   scope_active = 1;
 
