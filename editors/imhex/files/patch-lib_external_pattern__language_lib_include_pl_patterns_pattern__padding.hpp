--- lib/external/pattern_language/lib/include/pl/patterns/pattern_padding.hpp.orig	2022-07-17 13:36:36 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_padding.hpp
@@ -16,7 +16,7 @@ namespace pl {
             return "";
         }
 
-        [[nodiscard]] virtual std::vector<std::pair<u64, Pattern*>> getChildren() {
+        [[nodiscard]] std::vector<std::pair<u64, Pattern*>> getChildren() override {
             return { };
         }
 
