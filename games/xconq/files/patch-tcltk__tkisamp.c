--- tcltk/tkisamp.c.orig	2013-05-14 12:35:14.000000000 +0200
+++ tcltk/tkisamp.c	2013-05-14 12:39:19.000000000 +0200
@@ -258,7 +258,7 @@
 	return TCL_ERROR;
     }
 
-    interp->result = Tk_PathName(imfsample->tkwin);
+    Tcl_SetResult(interp, Tk_PathName(imfsample->tkwin), TCL_STATIC);
     return TCL_OK;
 }
 
@@ -305,7 +305,7 @@
 	}
     } else if ((c == 'c') && (strncmp(argv[1], "curselection", cmdlength) == 0)
 	       && (cmdlength >= 2)) {
-	sprintf(interp->result, "%d", imfsample->selected);
+	Tcl_SetObjResult(interp, Tcl_NewIntObj(imfsample->selected));
     } else if ((c == 'a') && (strncmp(argv[1], "add", cmdlength) == 0)
 	       && (cmdlength >= 2)) {
 	if (strcmp(argv[2], "imf") == 0) {
@@ -346,7 +346,7 @@
 		    sprintf(tclbuf, ".images.scroll set 0 1");
 		    rslt = Tcl_Eval(interp, tclbuf);
 		    if (rslt == TCL_ERROR) {
-			fprintf(stderr, "Error: %s\n", interp->result);
+			fprintf(stderr, "Error: %s\n", Tcl_GetStringResult(interp));
 		    }
 	    }
 	}
@@ -410,7 +410,7 @@
 		sprintf(tclbuf, ".images.scroll set %f %f", fraction, fraction2);
 		rslt = Tcl_Eval(interp, tclbuf);
 		if (rslt == TCL_ERROR) {
-			fprintf(stderr, "Error: %s\n", interp->result);
+			fprintf(stderr, "Error: %s\n", Tcl_GetStringResult(interp));
 		}
 	}
     } else {
@@ -448,12 +448,12 @@
 			images[i]->name);
 		rslt = Tcl_Eval(interp, tclbuf);
 		if (rslt == TCL_ERROR) {
-		    fprintf(stderr, "Error: %s\n", interp->result);
+		    fprintf(stderr, "Error: %s\n", Tcl_GetStringResult(interp));
 		}
 		sprintf(tclbuf, "update idletasks");
 		rslt = Tcl_Eval(interp, tclbuf);
 		if (rslt == TCL_ERROR) {
-		    fprintf(stderr, "Error: %s\n", interp->result);
+		    fprintf(stderr, "Error: %s\n", Tcl_GetStringResult(interp));
 		}
 	    }
 	    imf = tk_find_imf(images[i]->name);
@@ -782,7 +782,7 @@
 		    imfsample->height);
 	    rslt = Tcl_Eval(interp, tclbuf);
 	    if (rslt == TCL_ERROR) {
-		fprintf(stderr, "Error: %s\n", interp->result);
+		fprintf(stderr, "Error: %s\n", Tcl_GetStringResult(interp));
 	    }
 	    /* Force a redraw of the scrollbar if the window was resized. */
 	    if (imfsample->numimages) {
@@ -792,7 +792,7 @@
 	   }
 	    rslt = Tcl_Eval(interp, tclbuf);
 	    if (rslt == TCL_ERROR) {
-		fprintf(stderr, "Error: %s\n", interp->result);
+		fprintf(stderr, "Error: %s\n", Tcl_GetStringResult(interp));
 	    }
     }
     /* Now iterate through all the images we want to draw. */
