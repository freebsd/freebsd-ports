--- main/source/window/linux_window.cpp.orig	2023-07-08 16:57:04 UTC
+++ main/source/window/linux_window.cpp
@@ -19,8 +19,26 @@
     #include <imgui_impl_glfw.h>
     #include <string.h>
     #include <ranges>
+    #include <string_view>
+    #include <sstream>
 
 namespace hex {
+    // Brought from lib/external/pattern_language/external/cli11/include/CLI/impl/StringTools_inl.hpp
+    std::vector<std::string> split(const std::string &s, char delim) {
+        std::vector<std::string> elems;
+        // Check to see if empty string, give consistent result
+        if(s.empty()) {
+            elems.emplace_back();
+        } else {
+            std::stringstream ss;
+            ss.str(s);
+            std::string item;
+            while(std::getline(ss, item, delim)) {
+                elems.push_back(item);
+            }
+        }
+        return elems;
+    }
 
     bool isFileInPath(const std::fs::path &filename) {
         auto optPathVar = hex::getEnvironmentVariable("PATH");
@@ -29,7 +47,7 @@ namespace hex {
             return false;
         }
 
-        for (auto dir : std::views::split(optPathVar.value(), ':')) {
+        for (auto dir : split(optPathVar.value(), ':')) {
             if (std::fs::exists(std::fs::path(std::string_view(dir)) / filename)) {
                 return true;
             }
