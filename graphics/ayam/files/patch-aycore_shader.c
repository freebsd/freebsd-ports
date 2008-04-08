--- aycore/shader.c.orig	2007-09-21 13:30:37.000000000 +0200
+++ aycore/shader.c	2007-12-17 18:29:44.000000000 +0100
@@ -340,7 +340,7 @@
     }
 
 #ifndef WIN32
-  SLX_SetPath(Tcl_GetVar(ay_interp, vname, TCL_GLOBAL_ONLY|TCL_LEAVE_ERR_MSG));
+  SLX_SetPath((char *)Tcl_GetVar(ay_interp, vname, TCL_GLOBAL_ONLY|TCL_LEAVE_ERR_MSG));
 #else
   /* change all ; to : in shader search path */
   Tcl_DStringInit(&ds);
@@ -1094,7 +1094,8 @@
  ay_mat_object *material = NULL;
  ay_shader *newshader = NULL, **shader = NULL;
  ay_shader_arg *newarg = NULL, **argnext = NULL;
- char *result, *n1=NULL;
+ const char *result;
+ char *n1=NULL;
  int sargnc = 0, sargtc = 0, i, j, shadertype = 0, argtype = 0;
  double dtemp = 0.0;
  char **sargnv, **sargtv;
@@ -1287,10 +1288,10 @@
   /* decompose argument-list */
   Tcl_SplitList(interp,Tcl_GetVar2(interp, n1, "ArgNames",
 				   TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY),
-		&sargnc, &sargnv);
+		&sargnc, (const char ***)&sargnv);
   Tcl_SplitList(interp,Tcl_GetVar2(interp, n1, "ArgTypes",
 				   TCL_LEAVE_ERR_MSG | TCL_GLOBAL_ONLY),
-		&sargtc, &sargtv);
+		&sargtc, (const char ***)&sargtv);
 
 
   argnext = &(newshader->arg);
