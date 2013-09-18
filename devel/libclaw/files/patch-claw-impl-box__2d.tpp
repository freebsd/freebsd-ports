--- claw/impl/box_2d.tpp.orig	2013-07-03 23:34:38.000000000 +0400
+++ claw/impl/box_2d.tpp	2013-09-14 02:59:04.591227299 +0400
@@ -136,8 +136,8 @@
 claw::math::box_2d<U> claw::math::box_2d<T>::cast_value_type_to() const
 {
   return claw::math::box_2d<U>
-    ( first_point.cast_value_type_to<U>(),
-      second_point.cast_value_type_to<U>() );
+    ( first_point.template cast_value_type_to<U>(),
+      second_point.template cast_value_type_to<U>() );
 } // box_2d::cast_value_type_to()
 
 /*----------------------------------------------------------------------------*/
