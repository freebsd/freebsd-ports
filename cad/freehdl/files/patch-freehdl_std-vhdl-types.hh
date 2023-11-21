--- freehdl/std-vhdl-types.hh.orig	2013-02-25 17:33:20.000000000 +0000
+++ freehdl/std-vhdl-types.hh
@@ -1483,7 +1483,7 @@ A concat(array_info *ainfo, const A &a1,
   new_array.info->add_ref();
 
   /* Allocate memory for the data */
-  const int mem_size = length * ainfo->element_type->size();
+  const int mem_size = length * ainfo->element_type->size;
   new_array.data = (char*)internal_dynamic_alloc(mem_size);
 
   /* Note, scalar(...) can be evaluated at compile time. */
