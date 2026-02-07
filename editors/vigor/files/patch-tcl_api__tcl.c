--- ../tcl_api/tcl.c.orig
+++ ../tcl_api/tcl.c
@@ -73,7 +73,7 @@
 	if (getscreenid(interp, &sp, NULL, argv[1]))
 		return (TCL_ERROR);
 
-	(void)sprintf(interp->result, "%d", sp->id);
+	(void)sprintf(Tcl_GetStringResult(interp), "%d", sp->id);
 	return (TCL_OK);
 }
 
@@ -254,7 +254,7 @@
 	if (rval)
 		return (TCL_ERROR);
 
-	(void)sprintf(interp->result, "%lu", (unsigned long)last);
+	(void)sprintf(Tcl_GetStringResult(interp), "%lu", (unsigned long)last);
 	return (TCL_OK);
 }
 
@@ -520,7 +520,7 @@
 	if (rval)
 		return (TCL_ERROR);
 
-	(void)sprintf(interp->result, "%d", nsp->id);
+	(void)sprintf(Tcl_GetStringResult(interp), "%d", nsp->id);
 	return (TCL_OK);
 }
 
