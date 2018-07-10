--- gcc/stor-layout.c.orig	2013-04-28 17:29:18 UTC
+++ gcc/stor-layout.c
@@ -264,7 +264,7 @@ self_referential_size (tree size)
   fntype = build_function_type (return_type, param_type_list);
 
   /* Build the function declaration.  */
-  sprintf (buf, "SZ"HOST_WIDE_INT_PRINT_UNSIGNED, fnno++);
+  sprintf (buf, "SZ" HOST_WIDE_INT_PRINT_UNSIGNED, fnno++);
   fnname = get_file_function_name (buf);
   fndecl = build_decl (input_location, FUNCTION_DECL, fnname, fntype);
   for (t = param_decl_list; t; t = DECL_CHAIN (t))
