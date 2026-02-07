--- awelewish.c.orig	2013-07-08 14:02:50.000000000 +0200
+++ awelewish.c	2013-07-08 14:04:38.000000000 +0200
@@ -40,7 +40,7 @@
 {
     int level ;
     if ( argc !=3 ) {
-	interp->result = "wrong number of args in function setlevel" ;
+	Tcl_SetObjResult(interp, Tcl_NewStringObj("wrong number of args in function setlevel", -1));
 	return TCL_ERROR ;
     }
     sprintf(levelname , "%s" , argv[1]);
@@ -62,7 +62,7 @@
     AWELE *a ;
 
     if ( argc !=2 ) {
-	interp->result = "wrong number of args in function computer_play" ;
+	Tcl_SetObjResult(interp, Tcl_NewStringObj("wrong number of args in function computer_play", -1));
 	return TCL_ERROR ;
     }
     a = create_awele() ;
@@ -84,7 +84,7 @@
     AWELE *a ;
 
     if ( argc !=2 ) {
-	interp->result = "wrong number of args in function computer_rand_play" ;
+	Tcl_SetObjResult(interp, Tcl_NewStringObj("wrong number of args in function computer_rand_play", -1));
 	return TCL_ERROR ;
     }
     a = create_awele() ;
@@ -105,7 +105,7 @@
     AWELE *a ;
     int prof , cp , oldcp ;    
     if ( argc !=3 ) {
-	interp->result = "wrong number of args in function human_play" ;
+	Tcl_SetObjResult(interp, Tcl_NewStringObj("wrong number of args in function human_play", -1));
 	return TCL_ERROR ;
     }
     if ( Tcl_GetInt( interp , argv[1] , &cp ) != TCL_OK )
