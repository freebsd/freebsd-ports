--- k3dsdk/gil/boost/gil/extension/dynamic_image/apply_operation_base.hpp.orig	2012-06-20 07:41:16.000000000 +0900
+++ k3dsdk/gil/boost/gil/extension/dynamic_image/apply_operation_base.hpp	2012-06-20 16:07:44.000000000 +0900
@@ -114,7 +114,7 @@
     template <typename T2, typename Op>
     struct reduce_bind1 {
         const T2& _t2;
-        mutable Op&  _op;
+        Op&  _op;
 
         typedef typename Op::result_type result_type;
 
@@ -127,7 +127,7 @@
     struct reduce_bind2 {
         const Bits1& _bits1;
         std::size_t _index1;
-        mutable Op&  _op;
+        Op&  _op;
 
         typedef typename Op::result_type result_type;
 
