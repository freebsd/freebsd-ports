--- gcc/combine.c.orig	2013-05-03 13:19:51 UTC
+++ gcc/combine.c
@@ -6559,7 +6559,7 @@ simplify_logical (rtx x)
     case AND:
       /* We can call simplify_and_const_int only if we don't lose
 	 any (sign) bits when converting INTVAL (op1) to
-	 "unsigned HOST_WIDE_INT".  */
+	 "unsigned HOST_WIDE_INT ".  */
       if (CONST_INT_P (op1)
 	  && (HWI_COMPUTABLE_MODE_P (mode)
 	      || INTVAL (op1) > 0))
