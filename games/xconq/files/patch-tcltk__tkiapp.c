--- tcltk/tkiapp.c.orig	2013-05-14 12:39:37.000000000 +0200
+++ tcltk/tkiapp.c	2013-05-14 12:45:45.000000000 +0200
@@ -132,14 +132,15 @@
 static int
 get_imf_status_cmd(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d image families loaded", numimages);
+    Tcl_SetObjResult(interp, Tcl_NewIntObj(numimages));
+    Tcl_AppendResult(interp, " image families loaded");
     return TCL_OK;
 }
 
 static int
 get_numimages_cmd(ClientData cldata, Tcl_Interp *interp, int argc, char *argv[])
 {
-    sprintf(interp->result, "%d", numimages);
+    Tcl_SetObjResult(interp, Tcl_NewIntObj(numimages));
     return TCL_OK;
 }
 
@@ -167,7 +168,7 @@
     for_all_images(images[n], img)
       if (!img->synthetic)
 	++rslt;
-    sprintf(interp->result, "%d", rslt);
+    Tcl_SetObjResult(interp, Tcl_NewIntObj(rslt));
     return TCL_OK;
 }
 
@@ -249,7 +250,7 @@
 		rslt = Tcl_EvalFile(interp, pathbuf);
 		if (rslt == TCL_ERROR)
 		  init_error("Error reading tcl from %s: %s",
-			     pathbuf, interp->result);
+			     pathbuf, Tcl_GetStringResult(interp));
 		loaded = TRUE;
 		break;
 	    }
@@ -264,7 +265,7 @@
 			rslt = Tcl_EvalFile(interp, pathbuf);
 			if (rslt == TCL_ERROR)
 			  init_error("Error reading tcl from %s: %s",
-				     pathbuf, interp->result);
+				     pathbuf, Tcl_GetStringResult(interp));
 			loaded = TRUE;
 			break;
 		    }
