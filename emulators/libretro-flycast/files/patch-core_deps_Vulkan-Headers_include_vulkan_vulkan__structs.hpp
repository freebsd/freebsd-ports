--- core/deps/Vulkan-Headers/include/vulkan/vulkan_structs.hpp.orig	2023-11-06 20:05:46 UTC
+++ core/deps/Vulkan-Headers/include/vulkan/vulkan_structs.hpp
@@ -10,6 +10,15 @@
 
 #include <cstring>  // strcmp
 
+/* avoid conflict with macros from sys/types.h */
+#ifdef major
+# undef major
+#endif
+
+#ifdef minor
+# undef minor
+#endif
+
 namespace VULKAN_HPP_NAMESPACE
 {
   //===============
