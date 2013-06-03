--- generic/commands.c.orig	2013-06-03 14:05:27.000000000 +0200
+++ generic/commands.c	2013-06-03 14:06:34.000000000 +0200
@@ -83,7 +83,7 @@
 	  return TCL_OK;
 
 	case TCL_ERROR:
-	  sprintf(infomsg, "\n    (\"do\" body line %d)", frame->interp->errorLine);
+	  sprintf(infomsg, "\n    (\"do\" body line %d)", Tcl_GetErrorLine(frame->interp));
 	  Tcl_AddErrorInfo(frame->interp, infomsg);
 	  return TCL_ERROR;
 
@@ -124,7 +124,7 @@
 	  return TCL_OK;
 
 	case TCL_ERROR:
-	  sprintf(infomsg, "\n    (\"loop\" body line %d)", frame->interp->errorLine);
+	  sprintf(infomsg, "\n    (\"loop\" body line %d)", Tcl_GetErrorLine(frame->interp));
 	  Tcl_AddErrorInfo(frame->interp, infomsg);
 	  return TCL_ERROR;
 
