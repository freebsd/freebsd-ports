--- libs/mysql/serialization/archive.h.orig	2024-07-12 19:20:22 UTC
+++ libs/mysql/serialization/archive.h
@@ -81,14 +81,14 @@ class Archive {
   /// @note To be implemented in Archive_derived_type
   template <typename Type>
   static std::size_t get_size(Type &&arg) {
-    return Archive_derived_type::template get_size(std::forward<Type>(arg));
+    return Archive_derived_type::template get_size<>(std::forward<Type>(arg));
   }
 
   /// @brief Returns archive size - size of data written to the archive
   /// @return archive size - size of data written to the archive
   /// @note To be implemented in Archive_derived_type
   inline std::size_t get_size_written() const {
-    return Archive_derived_type::template get_size_written();
+    return Archive_derived_type::template get_size_written<>();
   }
 
   /// @brief Function returns maximum size of the Type
