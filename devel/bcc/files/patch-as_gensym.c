--- as/gensym.c.orig	1993-07-10 19:11:38 UTC
+++ as/gensym.c
@@ -201,7 +201,7 @@ bool_pt nameflag;
 			break;
 		}
 		else if ((unsigned) (*left)->value_reg_or_op.value <=
-			 (*right)->value_reg_or_op.value)
+			 (unsigned) (*right)->value_reg_or_op.value)
 		    break;
 		swap = *left;
 		*left = *right;
