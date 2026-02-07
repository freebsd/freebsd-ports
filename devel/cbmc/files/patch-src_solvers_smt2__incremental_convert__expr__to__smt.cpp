--- src/solvers/smt2_incremental/convert_expr_to_smt.cpp.orig	2025-01-07 17:23:07 UTC
+++ src/solvers/smt2_incremental/convert_expr_to_smt.cpp
@@ -175,14 +175,14 @@ static smt_termt make_bitvector_resize_cast(
   const bitvector_typet &from_type,
   const bitvector_typet &to_type)
 {
-  if(const auto to_fixedbv_type = type_try_dynamic_cast<fixedbv_typet>(to_type))
+  if([[maybe_unused]] const auto to_fixedbv_type = type_try_dynamic_cast<fixedbv_typet>(to_type))
   {
     UNIMPLEMENTED_FEATURE(
       "Generation of SMT formula for type cast to fixed-point bitvector "
       "type: " +
       to_type.pretty());
   }
-  if(const auto to_floatbv_type = type_try_dynamic_cast<floatbv_typet>(to_type))
+  if([[maybe_unused]] const auto to_floatbv_type = type_try_dynamic_cast<floatbv_typet>(to_type))
   {
     UNIMPLEMENTED_FEATURE(
       "Generation of SMT formula for type cast to floating-point bitvector "
@@ -258,7 +258,7 @@ static smt_termt convert_expr_to_smt(
   const auto &from_term = converted.at(cast.op());
   const typet &from_type = cast.op().type();
   const typet &to_type = cast.type();
-  if(const auto bool_type = type_try_dynamic_cast<bool_typet>(to_type))
+  if([[maybe_unused]] const auto bool_type = type_try_dynamic_cast<bool_typet>(to_type))
     return make_not_zero(from_term, cast.op().type());
   if(const auto c_bool_type = type_try_dynamic_cast<c_bool_typet>(to_type))
     return convert_c_bool_cast(from_term, from_type, *c_bool_type);
@@ -894,7 +894,7 @@ static smt_termt convert_expr_to_smt(
     "encoding.");
   const size_t offset_bits = type->get_width() - object_bits;
   if(
-    const auto symbol =
+    [[maybe_unused]] const auto symbol =
       expr_try_dynamic_cast<symbol_exprt>(address_of.object()))
   {
     const smt_bit_vector_constant_termt offset{0, offset_bits};
