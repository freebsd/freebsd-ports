fix Unparseable XSUB parameter: 'FNAME...' in Tcl.xs, line 113

--- Tcl.xs.orig	2025-07-13 08:42:18 UTC
+++ Tcl.xs
@@ -110,7 +110,7 @@ void
 	RETVAL
 
 void
-_eval_tcl_function(PKG, FNAME...)
+_eval_tcl_function(PKG, FNAME, ...)
      char*    PKG;
      char*    FNAME;
   PREINIT:
