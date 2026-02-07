--- src/solvers/flattening/boolbv_overflow.cpp.orig	2025-01-07 17:20:50 UTC
+++ src/solvers/flattening/boolbv_overflow.cpp
@@ -126,14 +126,14 @@ literalt boolbvt::convert_binary_overflow(const binary
       : bv_utilst::representationt::UNSIGNED;
 
   if(
-    const auto plus_overflow = expr_try_dynamic_cast<plus_overflow_exprt>(expr))
+    [[maybe_unused]] const auto plus_overflow = expr_try_dynamic_cast<plus_overflow_exprt>(expr))
   {
     if(bv0.size() != bv1.size())
       return SUB::convert_rest(expr);
 
     return bv_utils.overflow_add(bv0, bv1, rep);
   }
-  if(const auto minus = expr_try_dynamic_cast<minus_overflow_exprt>(expr))
+  if([[maybe_unused]] const auto minus = expr_try_dynamic_cast<minus_overflow_exprt>(expr))
   {
     if(bv0.size() != bv1.size())
       return SUB::convert_rest(expr);
@@ -159,7 +159,7 @@ literalt boolbvt::convert_binary_overflow(const binary
     return mult_overflow_result(prop, bv0, bv1, rep).back();
   }
   else if(
-    const auto shl_overflow = expr_try_dynamic_cast<shl_overflow_exprt>(expr))
+    [[maybe_unused]] const auto shl_overflow = expr_try_dynamic_cast<shl_overflow_exprt>(expr))
   {
     DATA_INVARIANT(!bv0.empty(), "zero-sized operand");
 
