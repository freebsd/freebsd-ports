--- boost/unordered/detail/foa/core.hpp.orig	2023-08-08 21:02:56 UTC
+++ boost/unordered/detail/foa/core.hpp
@@ -1870,9 +1870,10 @@ table_core:empty_value<Hash,0>,empty_value<Pred,1>,emp
 
   void fast_copy_elements_from(const table_core& x)
   {
-    if(arrays.elements){
+    if(arrays.elements&&x.arrays.elements){
       copy_elements_array_from(x);
       copy_groups_array_from(x);
+      size_ctrl.ml=std::size_t(x.size_ctrl.ml);
       size_ctrl.size=std::size_t(x.size_ctrl.size);
     }
   }
