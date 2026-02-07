--- ../ex/ex_tcl.c.orig
+++ ../ex/ex_tcl.c
@@ -71,7 +71,7 @@
 	    Tcl_Eval(gp->tcl_interp, cmdp->argv[0]->bp) == TCL_OK)
 		return (0);
 
-	msgq(sp, M_ERR, "Tcl: %s", ((Tcl_Interp *)gp->tcl_interp)->result);
+	msgq(sp, M_ERR, "Tcl: %s", Tcl_GetStringResult(gp->tcl_interp));
 	return (1);
 #else
 	msgq(sp, M_ERR, "302|Vi was not loaded with a Tcl interpreter");
