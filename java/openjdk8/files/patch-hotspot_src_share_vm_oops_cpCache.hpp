--- hotspot/src/share/vm/oops/cpCache.hpp.orig	2024-07-27 18:28:39 UTC
+++ hotspot/src/share/vm/oops/cpCache.hpp
@@ -192,7 +192,7 @@ class ConstantPoolCacheEntry VALUE_OBJ_CLASS_SPEC {
     field_index_mask           = right_n_bits(field_index_bits),
     parameter_size_bits        = 8,  // subset of field_index_mask, range is 0..255
     parameter_size_mask        = right_n_bits(parameter_size_bits),
-    option_bits_mask           = ~(((-1) << tos_state_shift) | (field_index_mask | parameter_size_mask))
+    option_bits_mask           = ~(((~0u) << tos_state_shift) | (field_index_mask | parameter_size_mask))
   };
 
   // specific bit definitions for the indices field:
