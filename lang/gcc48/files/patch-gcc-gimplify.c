Index: gcc/gimplify.c
===================================================================
--- gcc/gimplify.c	(revision 120301)
+++ gcc/gimplify.c	(working copy)
@@ -1013,8 +1013,9 @@
 	  /* The wrapper is on the RHS of an assignment that we're pushing
 	     down.  */
 	  gcc_assert (TREE_CODE (temp) == INIT_EXPR
-		      || TREE_CODE (temp) == MODIFY_EXPR);
-	  TREE_OPERAND (temp, 1) = *p;
+	              || TREE_CODE (temp) == MODIFY_EXPR
+	              || TREE_CODE (temp) == GIMPLE_MODIFY_STMT);
+	  GENERIC_TREE_OPERAND (temp, 1) = *p;
 	  *p = temp;
 	}
       else
