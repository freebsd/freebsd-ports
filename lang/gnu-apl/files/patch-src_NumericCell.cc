--- src/NumericCell.cc.orig	2019-06-23 12:39:20 UTC
+++ src/NumericCell.cc
@@ -1402,8 +1402,11 @@ NumericCell::bif_binomial(Cell * Z, const Cell * A) co
 
    if (!A->is_near_int())   return E_DOMAIN_ERROR;
    if (!is_near_int())      return E_DOMAIN_ERROR;
-   if (is_float_cell() && 0x7FFFFFFFFFFFFFFFLL < get_real_value())
-      return E_DOMAIN_ERROR;
+   if (is_float_cell())
+      {
+        if  (get_real_value() >  9223372036854775800.0)   return E_DOMAIN_ERROR;
+        if  (get_real_value() < -9223372036854775800.0)   return E_DOMAIN_ERROR;
+      }
 
 const APL_Integer a = A->get_checked_near_int();
 const APL_Integer b = get_checked_near_int();
