diff -urN ../SWIG1.3a5/Source/Modules1.1/guile.cxx ./Source/Modules1.1/guile.cxx
--- ../SWIG1.3a5/Source/Modules1.1/guile.cxx	Wed Sep 20 09:00:56 2000
+++ ./Source/Modules1.1/guile.cxx	Tue Feb 27 06:12:33 2001
@@ -13,10 +13,10 @@
  * can be used and distributed.
  *****************************************************************************/
 
-static char cvsroot[] = "$Header: /cvs/projects/SWIG/Source/Modules1.1/guile.cxx,v 1.68 2000/09/20 14:00:56 mkoeppe Exp $";
+static char cvsroot[] = "$Header: /cvs/projects/SWIG/Source/Modules1.1/guile.cxx,v 1.68.2.3 2001/02/26 17:57:56 mkoeppe Exp $";
 
 /***********************************************************************
- * $Header: /cvs/projects/SWIG/Source/Modules1.1/guile.cxx,v 1.68 2000/09/20 14:00:56 mkoeppe Exp $
+ * $Header: /cvs/projects/SWIG/Source/Modules1.1/guile.cxx,v 1.68.2.3 2001/02/26 17:57:56 mkoeppe Exp $
  *
  * guile.cxx
  *
@@ -252,6 +252,9 @@
 void
 GUILE::initialize (void)
 {
+  if (CPlusPlus) {
+    Printf(f_runtime, "extern \"C\" {\n\n");
+  }
   switch (linkage) {
   case GUILE_LSTYLE_SIMPLE:
     /* Simple linkage; we have to export the SWIG_init function. The user can
@@ -328,7 +331,7 @@
 {
   SwigType_emit_type_table (f_runtime, f_wrappers);
 
-  Printf (f_init, "SWIG_Guile_RegisterTypes(swig_types);\n");
+  Printf (f_init, "SWIG_Guile_RegisterTypes(swig_types, swig_types_initial);\n");
   Printf (f_init, "}\n\n");
   char module_name[256];
 
@@ -341,7 +344,10 @@
       strcpy(module_name,module);
   }
   emit_linkage (module_name);
-
+  if (CPlusPlus) {
+    Printf(f_init, "\n}\n");
+  }
+  
   if (procdoc) {
     Delete(procdoc);
     procdoc = NULL;
@@ -662,7 +668,7 @@
     Printv(f_wrappers, ");\n", 0);
     Printv(f_wrappers, "}\n", 0);
     /* Register it */
-    Printf (f_init, "gh_new_procedure(\"%s\", %s_rest, 0, 0, 1);\n",
+    Printf (f_init, "gh_new_procedure(\"%s\", (SCM (*) ()) %s_rest, 0, 0, 1);\n",
              proc_name, wname, numargs-numopt, numopt);
   }
   else if (emit_setters && struct_member && strlen(Char(proc_name))>3) {
@@ -675,7 +681,7 @@
       struct_member = 2; /* have a setter */
     }
     else Printf(f_init, "SCM getter = ");
-    Printf (f_init, "gh_new_procedure(\"%s\", %s, %d, %d, 0);\n",
+    Printf (f_init, "gh_new_procedure(\"%s\", (SCM (*) ()) %s, %d, %d, 0);\n",
 	    proc_name, wname, numargs-numopt, numopt);
     if (!is_setter) {
       /* Strip off "-get" */
@@ -698,7 +704,7 @@
   }
   else {
     /* Register the function */
-    Printf (f_init, "gh_new_procedure(\"%s\", %s, %d, %d, 0);\n",
+    Printf (f_init, "gh_new_procedure(\"%s\", (SCM (*) ()) %s, %d, %d, 0);\n",
 	    proc_name, wname, numargs-numopt, numopt);
   }
   if (procdoc) {
@@ -751,7 +757,7 @@
 
   if ((SwigType_type(t) != T_USER) || (is_a_pointer(t))) {
 
-    Printf (f_wrappers, "SCM %s(SCM s_0) {\n", var_name);
+    Printf (f_wrappers, "static SCM %s(SCM s_0)\n{\n", var_name);
 
     if (!(Status & STAT_READONLY) && SwigType_type(t) == T_STRING) {
       Printf (f_wrappers, "\t char *_temp;\n");
@@ -821,7 +827,7 @@
       throw_unhandled_guile_type_error (t);
     }
     Printf (f_wrappers, "\t return gswig_result;\n");
-    Printf (f_wrappers, "}\n");
+    Printf (f_wrappers, "}\n\n");
 
     // Now add symbol to the Guile interpreter
 
@@ -829,12 +835,12 @@
 	|| Status & STAT_READONLY) {
       /* Read-only variables become a simple procedure returning the
 	 value. */
-      Printf (f_init, "\t gh_new_procedure(\"%s\", %s, 0, 1, 0);\n",
+      Printf (f_init, "\t gh_new_procedure(\"%s\", (SCM (*) ()) %s, 0, 1, 0);\n",
 	      proc_name, var_name);
     }
     else {
       /* Read/write variables become a procedure with setter. */
-      Printf (f_init, "\t{ SCM p = gh_new_procedure(\"%s\", %s, 0, 1, 0);\n",
+      Printf (f_init, "\t{ SCM p = gh_new_procedure(\"%s\", (SCM (*) ()) %s, 0, 1, 0);\n",
 	      proc_name, var_name);
       Printf (f_init, "\t  gh_define(\"%s\", "
 	      "scm_make_procedure_with_setter(p, p)); }\n",
