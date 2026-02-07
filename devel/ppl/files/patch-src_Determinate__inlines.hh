--- src/Determinate_inlines.hh.orig	2016-02-11 12:31:26 UTC
+++ src/Determinate_inlines.hh
@@ -289,8 +289,8 @@ operator()(Determinate& x, const Determinate& y) const
 
 template <typename PSET>
 template <typename Binary_Operator_Assign>
-inline
-Determinate<PSET>::Binary_Operator_Assign_Lifter<Binary_Operator_Assign>
+inline typename
+Determinate<PSET>::template Binary_Operator_Assign_Lifter<Binary_Operator_Assign>
 Determinate<PSET>::lift_op_assign(Binary_Operator_Assign op_assign) {
   return Binary_Operator_Assign_Lifter<Binary_Operator_Assign>(op_assign);
 }
