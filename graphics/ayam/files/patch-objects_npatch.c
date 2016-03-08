--- objects/npatch.c.orig	2016-01-13 20:09:57 UTC
+++ objects/npatch.c
@@ -1970,7 +1970,7 @@ ay_npatch_setpropcb(Tcl_Interp *interp, 
     {
       Tcl_SplitList(interp, Tcl_GetVar2(interp, n1, "Knots_U",
 					TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY),
-		    &knotc, &knotv);
+		    &knotc, (const char ***)&knotv);
 
       if(!(nknotv = malloc(knotc * sizeof(double))))
 	{
@@ -2024,7 +2024,7 @@ ay_npatch_setpropcb(Tcl_Interp *interp, 
     {
       Tcl_SplitList(interp, Tcl_GetVar2(interp, n1, "Knots_V",
 				       TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY),
-		    &knotc, &knotv);
+		    &knotc, (const char ***)&knotv);
 
       if(!(nknotv = malloc(knotc * sizeof(double))))
 	{
