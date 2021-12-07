https://github.com/KhronosGroup/Vulkan-Hpp/issues/1161

--- include/vulkan/vulkan.hpp.orig	2021-12-07 09:36:34 UTC
+++ include/vulkan/vulkan.hpp
@@ -234,9 +234,23 @@ static_assert( VK_HEADER_VERSION == 202, "Wrong VK_HEA
 #  define VULKAN_HPP_NAMESPACE vk
 #endif
 
+template <typename T, typename = typename std::is_enum<T>::type>
+struct safe_underlying_type
+{
+  using type = T;
+};
+
+template <typename T>
+struct safe_underlying_type<T, std::true_type>
+{
+  using type = typename std::underlying_type<T>::type;
+};
+
 #if !defined( VULKAN_HPP_HASH_COMBINE )
-#  define VULKAN_HPP_HASH_COMBINE( valueType, seed, value ) \
-    seed ^= std::hash<std::remove_const<valueType>::type>{}( value ) + 0x9e3779b9 + ( seed << 6 ) + ( seed >> 2 )
+#  define VULKAN_HPP_HASH_COMBINE( valueType, seed, value )                              \
+    seed ^= std::hash<std::remove_const<safe_underlying_type<valueType>::type>::type>{}( \
+              static_cast<safe_underlying_type<valueType>::type>( value ) ) +            \
+            0x9e3779b9 + ( seed << 6 ) + ( seed >> 2 )
 #endif
 
 #define VULKAN_HPP_STRINGIFY2( text ) #text
