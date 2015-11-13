--- objects/npatch.c.orig	2015-06-23 18:03:50 UTC
+++ objects/npatch.c
@@ -1934,7 +1934,7 @@ ay_npatch_setpropcb(Tcl_Interp *interp, 
     {
       Tcl_SplitList(interp, Tcl_GetVar2(interp, n1, "Knots_U",
 					TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY),
-		    &knotc, &knotv);
+		    &knotc, (const char ***)&knotv);
 
       if(!(nknotv = malloc(knotc * sizeof(double))))
 	{
@@ -1988,7 +1988,7 @@ ay_npatch_setpropcb(Tcl_Interp *interp, 
     {
       Tcl_SplitList(interp, Tcl_GetVar2(interp, n1, "Knots_V",
 				       TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY),
-		    &knotc, &knotv);
+		    &knotc, (const char ***)&knotv);
 
       if(!(nknotv = malloc(knotc * sizeof(double))))
 	{
