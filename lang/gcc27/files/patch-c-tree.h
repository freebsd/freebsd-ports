--- c-tree.h.orig	Thu Jun 15 04:13:40 1995
+++ c-tree.h	Mon Mar 20 13:29:10 2000
@@ -159,7 +159,7 @@
 extern void declare_function_name               PROTO((void));
 extern void decl_attributes                     PROTO((tree, tree, tree));
 extern void init_function_format_info		PROTO((void));
-extern void record_function_format		PROTO((tree, tree, int, int, int));
+extern void record_function_format		PROTO((tree, tree, int, int, int, int));
 extern void check_function_format		PROTO((tree, tree, tree));
 /* Print an error message for invalid operands to arith operation CODE.
    NOP_EXPR is used as a special case (see truthvalue_conversion).  */
