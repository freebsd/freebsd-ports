--- objects/ncurve.c.orig	2007-12-17 18:38:58.000000000 +0100
+++ objects/ncurve.c	2007-12-17 18:39:11.000000000 +0100
@@ -731,7 +731,7 @@
       ay_error(AY_EOUTPUT, fname, "Checking new knots...");
       Tcl_SplitList(interp,Tcl_GetVar2(interp, n1, "Knots",
 				       TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY),
-		    &knotc, &knotv);
+		    &knotc, (const char ***)&knotv);
 
       if(!(nknotv = calloc(knotc, sizeof(double))))
 	{
