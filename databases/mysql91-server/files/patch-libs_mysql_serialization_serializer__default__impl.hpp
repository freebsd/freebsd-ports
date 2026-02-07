--- libs/mysql/serialization/serializer_default_impl.hpp.orig	2024-07-12 19:20:22 UTC
+++ libs/mysql/serialization/serializer_default_impl.hpp
@@ -233,7 +233,7 @@ std::size_t Serializer_default<Archive_concrete_type>:
 template <class Field_type, Field_size field_size_defined, typename Enabler>
 std::size_t Serializer_default<Archive_concrete_type>::get_field_size(
     const Field_type &field) {
-  return Archive_concrete_type::template get_size(
+  return Archive_concrete_type::template get_size<>(
       Field_wrapper<const Field_type, field_size_defined>(field));
 }
 
@@ -473,7 +473,7 @@ std::size_t Serializer_default<Archive_concrete_type>:
   std::size_t calculated_size = 0;
   bool is_provided = field_definition.run_encode_predicate();
   if (is_provided) {
-    auto size_id_type = Archive_concrete_type::template get_size(
+    auto size_id_type = Archive_concrete_type::template get_size<>(
         create_varlen_field_wrapper(field_id));
     calculated_size = get_field_size<Field_type, field_size_defined>(
                           field_definition.get_ref()) +
@@ -489,18 +489,18 @@ std::size_t Serializer_default<Archive_concrete_type>:
     bool skip_id) {
   std::size_t serializable_overhead_type = 0;
   if (skip_id == false) {
-    serializable_overhead_type = Archive_concrete_type::template get_size(
+    serializable_overhead_type = Archive_concrete_type::template get_size<>(
         create_varlen_field_wrapper(field_id));
   }
   auto serializable_size = serializable.template get_size_internal<Base_type>();
-  auto serializable_overhead_size = Archive_concrete_type::template get_size(
+  auto serializable_overhead_size = Archive_concrete_type::template get_size<>(
       create_varlen_field_wrapper(serializable_size));
 
   Field_id_type last_non_ignorable_field_id =
       find_last_non_ignorable_field_id(serializable);
 
   auto serializable_overhead_last_non_ignorable_field_id =
-      Archive_concrete_type::template get_size(
+      Archive_concrete_type::template get_size<>(
           create_varlen_field_wrapper(last_non_ignorable_field_id));
   return serializable_overhead_type + serializable_overhead_size +
          serializable_overhead_last_non_ignorable_field_id + serializable_size;
