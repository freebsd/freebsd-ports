--- jsoncpp-namespaced-targets.cmake.orig	2026-06-14 03:16:10 UTC
+++ jsoncpp-namespaced-targets.cmake
@@ -1,9 +1,11 @@ if (NOT TARGET JsonCpp::JsonCpp)
 if (NOT TARGET JsonCpp::JsonCpp)
-    if (TARGET jsoncpp_static)
+    # Prefer shared library over static library.
+    # This diverges from upstream but makes more sense in Debian
+    if (TARGET jsoncpp_lib)
         add_library(JsonCpp::JsonCpp INTERFACE IMPORTED)
-        set_target_properties(JsonCpp::JsonCpp PROPERTIES INTERFACE_LINK_LIBRARIES "jsoncpp_static")
-    elseif (TARGET jsoncpp_lib)
-        add_library(JsonCpp::JsonCpp INTERFACE IMPORTED)
         set_target_properties(JsonCpp::JsonCpp PROPERTIES INTERFACE_LINK_LIBRARIES "jsoncpp_lib")
+    elseif (TARGET jsoncpp_static)
+        add_library(JsonCpp::JsonCpp INTERFACE IMPORTED)
+        set_target_properties(JsonCpp::JsonCpp PROPERTIES INTERFACE_LINK_LIBRARIES "jsoncpp_static")
     endif ()
 endif ()
