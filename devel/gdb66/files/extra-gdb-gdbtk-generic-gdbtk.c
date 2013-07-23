--- gdb/gdbtk/generic/gdbtk.c.orig	2013-07-15 11:44:12.000000000 +0200
+++ gdb/gdbtk/generic/gdbtk.c	2013-07-15 11:45:50.000000000 +0200
@@ -468,7 +468,7 @@
   Tcl_Free ((char *) exec_path);
 
   if (Tcl_Init (gdbtk_interp) != TCL_OK)
-    error ("Tcl_Init failed: %s", gdbtk_interp->result);
+    error ("Tcl_Init failed: %s", Tcl_GetStringResult(gdbtk_interp));
 
   /* Set up some globals used by gdb to pass info to gdbtk
      for start up options and the like */
@@ -486,23 +486,23 @@
 
   /* Initialize the Paths variable.  */
   if (ide_initialize_paths (gdbtk_interp, "") != TCL_OK)
-    error ("ide_initialize_paths failed: %s", gdbtk_interp->result);
+    error ("ide_initialize_paths failed: %s", Tcl_GetStringResult(gdbtk_interp));
 
   if (Tk_Init (gdbtk_interp) != TCL_OK)
-    error ("Tk_Init failed: %s", gdbtk_interp->result);
+    error ("Tk_Init failed: %s", Tcl_GetStringResult(gdbtk_interp));
 
   if (Itcl_Init (gdbtk_interp) == TCL_ERROR)
-    error ("Itcl_Init failed: %s", gdbtk_interp->result);
+    error ("Itcl_Init failed: %s", Tcl_GetStringResult(gdbtk_interp));
   Tcl_StaticPackage (gdbtk_interp, "Itcl", Itcl_Init,
 		     (Tcl_PackageInitProc *) NULL);
 
   if (Itk_Init (gdbtk_interp) == TCL_ERROR)
-    error ("Itk_Init failed: %s", gdbtk_interp->result);
+    error ("Itk_Init failed: %s", Tcl_GetStringResult(gdbtk_interp));
   Tcl_StaticPackage (gdbtk_interp, "Itk", Itk_Init,
 		     (Tcl_PackageInitProc *) NULL);
 
   if (Tktable_Init (gdbtk_interp) != TCL_OK)
-    error ("Tktable_Init failed: %s", gdbtk_interp->result);
+    error ("Tktable_Init failed: %s", Tcl_GetStringResult(gdbtk_interp));
 
   Tcl_StaticPackage (gdbtk_interp, "Tktable", Tktable_Init,
 		     (Tcl_PackageInitProc *) NULL);
@@ -540,7 +540,7 @@
 
   if (Gdbtk_Init (gdbtk_interp) != TCL_OK)
     {
-      error ("Gdbtk_Init failed: %s", gdbtk_interp->result);
+      error ("Gdbtk_Init failed: %s", Tcl_GetStringResult(gdbtk_interp));
     }
 
   Tcl_StaticPackage (gdbtk_interp, "Insight", Gdbtk_Init, NULL);
@@ -719,7 +719,7 @@
 
   retval = Tcl_Eval (gdbtk_interp, cmd);
 
-  result = xstrdup (gdbtk_interp->result);
+  result = xstrdup (Tcl_GetStringResult(gdbtk_interp));
 
   old_chain = make_cleanup (free, result);
 
