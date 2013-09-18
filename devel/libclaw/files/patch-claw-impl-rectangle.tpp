--- claw/impl/rectangle.tpp.orig	2013-07-03 23:34:38.000000000 +0400
+++ claw/impl/rectangle.tpp	2013-09-14 02:57:21.105226690 +0400
@@ -140,7 +140,7 @@
 claw::math::rectangle<U> claw::math::rectangle<T>::cast_value_type_to() const
 {
   return claw::math::rectangle<U>
-    ( position.cast_value_type_to<U>(), (U)width, (U)height );
+    ( position.template cast_value_type_to<U>(), (U)width, (U)height );
 } // rectangle::cast_value_type_to()
 
 /*----------------------------------------------------------------------------*/
