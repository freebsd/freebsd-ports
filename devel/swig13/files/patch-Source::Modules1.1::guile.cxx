Index: SWIG/Source/Modules1.1/guile.cxx
diff -u SWIG/Source/Modules1.1/guile.cxx:1.68 SWIG/Source/Modules1.1/guile.cxx:1.68.2.6
--- Source/Modules1.1/guile.cxx:1.68	Wed Sep 20 09:00:56 2000
+++ Source/Modules1.1/guile.cxx	Fri Mar  2 07:53:02 2001
@@ -32,8 +32,10 @@
      -prefix name    - Use NAME as prefix [default \"gswig_\"]\n\
      -package name   - Set the path of the module [default NULL]\n\
      -Linkage lstyle - Use linkage protocol LSTYLE [default `ltdlmod']\n\
-     -procdoc file   - Output procedure documentation to file\n\
+     -procdoc file   - Output procedure documentation to FILE\n\
 \n\
+     -procdocformat format - Output procedure documentation in FORMAT;\n\
+                             one of `guile-1.4', `plain', `texinfo'\n\
   The module option does not create a guile module with a separate name\n\
   space.  It specifies the name of the initialization function and is\n\
   called a module here so that it is compadible with the rest of SWIG.\n\
@@ -59,8 +61,10 @@
   package = NULL;
   linkage = GUILE_LSTYLE_SIMPLE;
   procdoc = NULL;
+  docformat = GUILE_1_4;
   emit_setters = 0;
   struct_member = 0;
+  before_return = NULL;
 }
 
 // ---------------------------------------------------------------------
@@ -143,6 +147,18 @@
 	  Swig_arg_error();
         }
       }
+      else if (strcmp (argv[i], "-procdocformat") == 0) {
+	if (strcmp(argv[i+1], "guile-1.4") == 0)
+	  docformat = GUILE_1_4;
+	else if (strcmp(argv[i+1], "plain") == 0)
+	  docformat = PLAIN;
+	else if (strcmp(argv[i+1], "texinfo") == 0)
+	  docformat = TEXINFO;
+	else Swig_arg_error();
+	Swig_mark_arg(i);
+	Swig_mark_arg(i+1);
+	i++;
+      }
       else if (strcmp (argv[i], "-emit-setters") == 0) {
 	emit_setters = 1;
 	Swig_mark_arg (i);
@@ -252,6 +268,9 @@
 void
 GUILE::initialize (void)
 {
+  if (CPlusPlus) {
+    Printf(f_runtime, "extern \"C\" {\n\n");
+  }
   switch (linkage) {
   case GUILE_LSTYLE_SIMPLE:
     /* Simple linkage; we have to export the SWIG_init function. The user can
@@ -328,7 +347,7 @@
 {
   SwigType_emit_type_table (f_runtime, f_wrappers);
 
-  Printf (f_init, "SWIG_Guile_RegisterTypes(swig_types);\n");
+  Printf (f_init, "SWIG_Guile_RegisterTypes(swig_types, swig_types_initial);\n");
   Printf (f_init, "}\n\n");
   char module_name[256];
 
@@ -341,7 +360,10 @@
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
@@ -460,6 +482,35 @@
   error_count++;
 }
 
+
+/* Write out procedure documentation */
+
+void
+GUILE::write_doc(const String *proc_name,
+		 const String *signature,
+		 const String *doc)
+{
+  switch (docformat) {
+  case GUILE_1_4:
+    Printv(procdoc, "\f\n", 0);
+    Printv(procdoc, "(", signature, ")\n", 0);
+    Printv(procdoc, doc, "\n", 0);
+    break;
+  case PLAIN:
+    Printv(procdoc, "\f", proc_name, "\n\n", 0);
+    Printv(procdoc, "(", signature, ")\n", 0);
+    Printv(procdoc, doc, "\n\n", 0);
+    break;
+  case TEXINFO:
+    Printv(procdoc, "\f", proc_name, "\n", 0);
+    Printv(procdoc, "@deffn primitive ", signature, "\n", 0);
+    Printv(procdoc, doc, "\n", 0);
+    Printv(procdoc, "@end deffn\n\n", 0);
+    break;
+  }
+}
+
+
 // ----------------------------------------------------------------------
 // GUILE::create_function(char *name, char *iname, SwigType *d,
 //                             ParmList *l)
@@ -498,6 +549,7 @@
   /* Declare return variable */
 
   Wrapper_add_local (f,"gswig_result", "SCM gswig_result");
+  Wrapper_add_local (f,"gswig_list_p", "SCM gswig_list_p = 0");
 
   if (procdoc)
     guile_do_doc_typemap(returns, "outdoc", d, NULL,
@@ -506,7 +558,7 @@
   /* Open prototype and signature */
 
   Printv(f->def, "static SCM\n", wname," (", 0);
-  Printv(signature, "(", proc_name, 0);
+  Printv(signature, proc_name, 0);
 
   /* Now write code to extract the parameters */
 
@@ -583,9 +635,8 @@
 		     source, target, numargs, proc_name, f, 0);
   }
 
-  /* Close prototype and signature */
+  /* Close prototype */
 
-  Printv(signature, ")\n", 0);
   Printf(f->def, ")\n{\n");
 
   /* Define the scheme name in C. This define is used by several Guile
@@ -637,6 +688,8 @@
 
   // Wrap things up (in a manner of speaking)
 
+  if (before_return)
+    Printv(f->code, before_return, "\n", 0);
   Printv(f->code, "return gswig_result;\n", 0);
 
   // Undefine the scheme name
@@ -662,7 +715,7 @@
     Printv(f_wrappers, ");\n", 0);
     Printv(f_wrappers, "}\n", 0);
     /* Register it */
-    Printf (f_init, "gh_new_procedure(\"%s\", %s_rest, 0, 0, 1);\n",
+    Printf (f_init, "gh_new_procedure(\"%s\", (SCM (*) ()) %s_rest, 0, 0, 1);\n",
              proc_name, wname, numargs-numopt, numopt);
   }
   else if (emit_setters && struct_member && strlen(Char(proc_name))>3) {
@@ -675,7 +728,7 @@
       struct_member = 2; /* have a setter */
     }
     else Printf(f_init, "SCM getter = ");
-    Printf (f_init, "gh_new_procedure(\"%s\", %s, %d, %d, 0);\n",
+    Printf (f_init, "gh_new_procedure(\"%s\", (SCM (*) ()) %s, %d, %d, 0);\n",
 	    proc_name, wname, numargs-numopt, numopt);
     if (!is_setter) {
       /* Strip off "-get" */
@@ -698,17 +751,17 @@
   }
   else {
     /* Register the function */
-    Printf (f_init, "gh_new_procedure(\"%s\", %s, %d, %d, 0);\n",
+    Printf (f_init, "gh_new_procedure(\"%s\", (SCM (*) ()) %s, %d, %d, 0);\n",
 	    proc_name, wname, numargs-numopt, numopt);
   }
   if (procdoc) {
-    /* Write out procedure documentation */
-    Printv(signature, "Returns ", 0);
-    if (Len(returns)==0) Printv(signature, "unspecified", 0);
-    else if (returns_list) Printv(signature, "list (", returns, ")", 0);
-    else Printv(signature, returns, 0);
-    Printv(signature, "\n", 0);
-    Printv(procdoc, "\f\n", signature, 0);
+    String *returns_text = NewString("");
+    Printv(returns_text, "Returns ", 0);
+    if (Len(returns)==0) Printv(returns_text, "unspecified", 0);
+    else if (returns_list) Printv(returns_text, "list (", returns, ")", 0);
+    else Printv(returns_text, returns, 0);
+    write_doc(proc_name, signature, returns_text);
+    Delete(returns_text);
   }
 
   Delete(proc_name);
@@ -751,7 +804,7 @@
 
   if ((SwigType_type(t) != T_USER) || (is_a_pointer(t))) {
 
-    Printf (f_wrappers, "SCM %s(SCM s_0) {\n", var_name);
+    Printf (f_wrappers, "static SCM %s(SCM s_0)\n{\n", var_name);
 
     if (!(Status & STAT_READONLY) && SwigType_type(t) == T_STRING) {
       Printf (f_wrappers, "\t char *_temp;\n");
@@ -821,7 +874,7 @@
       throw_unhandled_guile_type_error (t);
     }
     Printf (f_wrappers, "\t return gswig_result;\n");
-    Printf (f_wrappers, "}\n");
+    Printf (f_wrappers, "}\n\n");
 
     // Now add symbol to the Guile interpreter
 
@@ -829,12 +882,12 @@
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
@@ -844,29 +897,28 @@
     if (procdoc) {
       /* Compute documentation */
       String *signature = NewString("");
+      String *doc = NewString("");
 
       if (Status & STAT_READONLY) {
-	Printv(signature, "(", proc_name, ")\n", 0);
-	Printv(signature, "Returns constant ", 0);
-	guile_do_doc_typemap(signature, "varoutdoc", t, NULL,
+	Printv(signature, proc_name, 0);
+	Printv(doc, "Returns constant ", 0);
+	guile_do_doc_typemap(doc, "varoutdoc", t, NULL,
 			     0, proc_name, f);
-	Printv(signature, "\n", 0);
       }
       else {
-	Printv(signature, "(", proc_name,
+	Printv(signature, proc_name,
 	       " #:optional ", 0);
 	guile_do_doc_typemap(signature, "varindoc", t, "new-value",
 			     1, proc_name, f);
-	Printv(signature, ")\n", 0);
-	Printv(signature, "If NEW-VALUE is provided, "
+	Printv(doc, "If NEW-VALUE is provided, "
 	       "set C variable to this value.\n", 0);
-	Printv(signature, "Returns variable value ", 0);
-	guile_do_doc_typemap(signature, "varoutdoc", t, NULL,
+	Printv(doc, "Returns variable value ", 0);
+	guile_do_doc_typemap(doc, "varoutdoc", t, NULL,
 			     0, proc_name, f);
-	Printv(signature, "\n", 0);
       }
-      Printv(procdoc, "\f\n", signature, 0);
+      write_doc(proc_name, signature, doc);
       Delete(signature);
+      Delete(doc);
     }
 
   } else {
@@ -957,5 +1009,16 @@
   else {
     /* Only emit traditional VAR-get and VAR-set procedures */
     Language::cpp_variable(name, iname, t);
+  }
+}
+
+void GUILE::pragma(char *lang, char *cmd, char *value)
+{
+  if (strcmp(lang,(char*)"guile") == 0) {
+    if (strcmp(cmd, (char*)"beforereturn")==0) {
+      if (before_return)
+	Delete(before_return);
+      before_return = NewString(value);
+    }
   }
 }
