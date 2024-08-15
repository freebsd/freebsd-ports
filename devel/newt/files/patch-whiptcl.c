--- whiptcl.c.orig	2023-10-25 10:21:25 UTC
+++ whiptcl.c
@@ -138,45 +138,45 @@ static int wtCmd(ClientData clientData, Tcl_Interp * i
     
     if (arg < -1) {
 	/* this could buffer oveflow, bug we're not setuid so I don't care */
-	interp->result = malloc(200);
-	interp->freeProc = TCL_DYNAMIC;
-	sprintf(interp->result, "%s: %s\n", 
+	char *tmp = malloc(200);
+	sprintf(tmp, "%s: %s\n", 
 		poptBadOption(optCon, POPT_BADOPTION_NOALIAS), 
 		poptStrerror(arg));
+	Tcl_SetResult(interp, tmp, TCL_DYNAMIC);
 
 	return TCL_ERROR;
     }
 
     if (mode == MODE_NONE) {
-	interp->result = "no dialog mode was specified";
+	Tcl_SetResult(interp, "no dialog mode was specified", TCL_STATIC);
 	return TCL_ERROR;
     } else if (rc) {
-	interp->result = "multiple modes were specified";
+	Tcl_SetResult(interp, "multiple modes were specified", TCL_STATIC);
 	return TCL_ERROR;
     }
 
     if (!(text = poptGetArg(optCon))) {
-	interp->result = "missing text parameter";
+	Tcl_SetResult(interp, "missing text parameter", TCL_STATIC);
 	return TCL_ERROR;
     }
 
     if (!(nextArg = poptGetArg(optCon))) {
-	interp->result = "height missing";
+	Tcl_SetResult(interp, "height missing", TCL_STATIC);
 	return TCL_ERROR;
     }
     height = strtoul(nextArg, &end, 10);
     if (*end) {
-	interp->result = "height is not a number";
+	Tcl_SetResult(interp, "height is not a number", TCL_STATIC);
 	return TCL_ERROR;
     }
 
     if (!(nextArg = poptGetArg(optCon))) {
-	interp->result = "width missing";
+	Tcl_SetResult(interp, "width missing", TCL_STATIC);
 	return TCL_ERROR;
     }
     width = strtoul(nextArg, &end, 10);
     if (*end) {
-	interp->result = "width is not a number";
+	Tcl_SetResult(interp, "width is not a number", TCL_STATIC);
 	return TCL_ERROR;
     }
 
@@ -267,7 +267,7 @@ static int wtCmd(ClientData clientData, Tcl_Interp * i
     newtPopWindow();
 
     if (rc == DLG_ERROR) {
-	interp->result = "bad paramter for whiptcl dialog box";
+	Tcl_SetResult(interp, "bad paramter for whiptcl dialog box", TCL_STATIC);
 	return TCL_ERROR;
     } 
 
