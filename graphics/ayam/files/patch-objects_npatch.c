--- objects/npatch.c.orig	2007-12-17 18:39:37.000000000 +0100
+++ objects/npatch.c	2007-12-17 18:40:02.000000000 +0100
@@ -1260,7 +1260,7 @@
       ay_error(AY_EOUTPUT, fname, "Checking new knots for U...");
       Tcl_SplitList(interp, Tcl_GetVar2(interp, n1, "Knots_U",
 					TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY),
-		    &knotc, &knotv);
+		    &knotc, (const char ***)&knotv);
 
       if(!(nknotv = calloc(knotc, sizeof(double))))
 	{
@@ -1324,7 +1324,7 @@
       ay_error(AY_EOUTPUT, fname, "Checking new knots for V...");
       Tcl_SplitList(interp,Tcl_GetVar2(interp, n1, "Knots_V",
 				       TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY),
-		    &knotc, &knotv);
+		    &knotc, (const char ***)&knotv);
 
       if(!(nknotv = calloc(knotc, sizeof(double))))
 	{
