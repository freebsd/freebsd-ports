--- main/source/window/window.cpp.orig	2023-04-09 06:24:47 UTC
+++ main/source/window/window.cpp
@@ -272,7 +272,7 @@ namespace hex {
         }
     }
 
-    static void createNestedMenu(std::span<const std::string> menuItems, const Shortcut &shortcut, const std::function<void()> &callback, const std::function<bool()> &enabledCallback) {
+    static void createNestedMenu(const std::vector<std::string> &menuItems, const Shortcut &shortcut, const std::function<void()> &callback, const std::function<bool()> &enabledCallback) {
         const auto &name = menuItems.front();
 
         if (name == ContentRegistry::Interface::impl::SeparatorValue) {
