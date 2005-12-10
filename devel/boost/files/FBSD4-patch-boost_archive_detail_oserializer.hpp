--- boost/archive/detail/oserializer.hpp.orig	Thu Nov 10 00:40:32 2005
+++ boost/archive/detail/oserializer.hpp	Thu Nov 10 00:43:15 2005
@@ -330,9 +330,9 @@
     {
         static const basic_pointer_oserializer * register_type(Archive & /* ar */){
             // it has? to be polymorphic
-            BOOST_STATIC_ASSERT(
-                boost::serialization::type_info_implementation<T>::type::is_polymorphic::value
-            );
+            //BOOST_STATIC_ASSERT(
+                //boost::serialization::type_info_implementation<T>::type::is_polymorphic::value
+            //);
             return static_cast<const basic_pointer_oserializer *>(NULL);
         }
     };
