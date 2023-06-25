--- src/boost/boost/container_hash/hash.hpp.orig	2023-03-09 16:36:47 UTC
+++ src/boost/boost/container_hash/hash.hpp
@@ -118,20 +118,12 @@ namespace boost
 {
     namespace hash_detail
     {
-#if defined(_HAS_AUTO_PTR_ETC) && !_HAS_AUTO_PTR_ETC
         template <typename T>
         struct hash_base
         {
             typedef T argument_type;
             typedef std::size_t result_type;
         };
-#else
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
-        template <typename T>
-        struct hash_base : std::unary_function<T, std::size_t> {};
-#pragma GCC diagnostic pop
-#endif
 
         struct enable_hash_value { typedef std::size_t type; };
 
