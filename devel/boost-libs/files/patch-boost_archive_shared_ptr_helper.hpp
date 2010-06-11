Index: boost/archive/shared_ptr_helper.hpp
===================================================================
--- boost/archive/shared_ptr_helper.hpp (revision 55789)
+++ boost/archive/shared_ptr_helper.hpp (revision 57981)
@@ -109,5 +110,5 @@
         static const boost::serialization::extended_type_info * 
         get_object_identifier(T & t){
-            return boost::serialization::singleton<
+            return & boost::serialization::singleton<
                 BOOST_DEDUCED_TYPENAME 
                 boost::serialization::type_info_implementation<T>::type
