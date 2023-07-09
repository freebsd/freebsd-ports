--- main/source/window/window.cpp.orig	2023-06-24 10:07:39 UTC
+++ main/source/window/window.cpp
@@ -220,7 +220,7 @@ namespace hex {
         }
     }
 
-    static void createNestedMenu(std::span<const std::string> menuItems, const Shortcut &shortcut, const std::function<void()> &callback, const std::function<bool()> &enabledCallback) {
+    static void createNestedMenu(const std::vector<std::string> &menuItems, const Shortcut &shortcut, const std::function<void()> &callback, const std::function<bool()> &enabledCallback) {
         const auto &name = menuItems.front();
 
         if (name == ContentRegistry::Interface::impl::SeparatorValue) {
