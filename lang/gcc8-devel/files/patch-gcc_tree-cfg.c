--- UTC
Index: gcc/tree-cfg.c
===================================================================
--- gcc/tree-cfg.c	(revision 255155)
+++ gcc/tree-cfg.c	(working copy)
@@ -3994,7 +3994,7 @@
       {
 	if (!POINTER_TYPE_P (rhs1_type)
 	    || !POINTER_TYPE_P (rhs2_type)
-	    || !types_compatible_p (rhs1_type, rhs2_type)
+//	    || !types_compatible_p (rhs1_type, rhs2_type)
 	    || TREE_CODE (lhs_type) != INTEGER_TYPE
 	    || TYPE_UNSIGNED (lhs_type)
 	    || TYPE_PRECISION (lhs_type) != TYPE_PRECISION (rhs1_type))
