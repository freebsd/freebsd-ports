Temporarily revert an upstream commit that breaks i386 / i586.
Cf. https://gcc.gnu.org/bugzilla/show_bug.cgi?id=99422

--- gcc/lra-constraints.c.orig	2021-03-07 22:32:27.000000000 +0000
+++ gcc/lra-constraints.c	2021-03-08 20:41:16.094547000 +0000
@@ -3450,9 +3450,8 @@
      i.e. bcst_mem_operand in i386 backend.  */
   else if (MEM_P (mem)
 	   && !(INSN_CODE (curr_insn) < 0
-		&& (cn == CONSTRAINT__UNKNOWN
-		    || (get_constraint_type (cn) == CT_FIXED_FORM
-			&& constraint_satisfied_p (op, cn)))))
+		&& get_constraint_type (cn) == CT_FIXED_FORM
+	        && constraint_satisfied_p (op, cn)))
     decompose_mem_address (&ad, mem);
   else if (GET_CODE (op) == SUBREG
 	   && MEM_P (SUBREG_REG (op)))
