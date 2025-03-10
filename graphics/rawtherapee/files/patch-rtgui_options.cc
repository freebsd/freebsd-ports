--- rtgui/options.cc.orig	2024-08-24 18:33:56 UTC
+++ rtgui/options.cc
@@ -1273,7 +1273,7 @@ void Options::readFromFile(Glib::ustring fname)
                 std::map<std::string, int> checkedExtensions;
 
                 if (parseExtensions.size() == parseExtensionsEnabled.size()) {
-                    for (auto i = 0; i < parseExtensions.size(); ++i) {
+                    for (size_t i = 0; i < parseExtensions.size(); ++i) {
                         checkedExtensions[parseExtensions[i]] = parseExtensionsEnabled[i];
                     }
                 }
