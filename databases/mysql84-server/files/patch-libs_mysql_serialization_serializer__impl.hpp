--- libs/mysql/serialization/serializer_impl.hpp.orig	2024-07-12 19:20:22 UTC
+++ libs/mysql/serialization/serializer_impl.hpp
@@ -51,8 +51,8 @@ Serializer<Serializer_derived_type, Archive_type>::get
 Serializer<Serializer_derived_type, Archive_type>::get_size_field_def(
     Field_id_type field_id,
     const Field_definition<Field_type, field_size_defined> &field_definition) {
-  return Serializer_derived_type::template get_size_field_def(field_id,
-                                                              field_definition);
+  return Serializer_derived_type::template get_size_field_def<>(
+      field_id, field_definition);
 }
 
 template <class Serializer_derived_type, class Archive_type>
@@ -61,7 +61,7 @@ Serializer<Serializer_derived_type, Archive_type>::get
 Serializer<Serializer_derived_type, Archive_type>::get_size_serializable(
     Field_id_type field_id, const Serializable_concrete_type &serializable,
     bool skip_id) {
-  return Serializer_derived_type::template get_size_serializable(
+  return Serializer_derived_type::template get_size_serializable<>(
       field_id, serializable, skip_id);
 }
 
