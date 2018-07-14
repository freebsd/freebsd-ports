--- gcc/ipa-prop.c.orig	2018-07-13 20:22:39 UTC
+++ gcc/ipa-prop.c
@@ -244,7 +244,7 @@ ipa_print_node_jump_functions_for_edge (
 	{
 	  fprintf (f, "KNOWN TYPE: base  ");
 	  print_generic_expr (f, jump_func->value.known_type.base_type, 0);
-	  fprintf (f, ", offset "HOST_WIDE_INT_PRINT_DEC", component ",
+	  fprintf (f, ", offset " HOST_WIDE_INT_PRINT_DEC ", component ",
 		   jump_func->value.known_type.offset);
 	  print_generic_expr (f, jump_func->value.known_type.component_type, 0);
 	  fprintf (f, "\n");
@@ -284,7 +284,7 @@ ipa_print_node_jump_functions_for_edge (
       else if (type == IPA_JF_ANCESTOR)
 	{
 	  fprintf (f, "ANCESTOR: ");
-	  fprintf (f, "%d, offset "HOST_WIDE_INT_PRINT_DEC", ",
+	  fprintf (f, "%d, offset " HOST_WIDE_INT_PRINT_DEC ", ",
 		   jump_func->value.ancestor.formal_id,
 		   jump_func->value.ancestor.offset);
 	  print_generic_expr (f, jump_func->value.ancestor.type, 0);
