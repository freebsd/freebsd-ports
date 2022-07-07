--- lib/external/pattern_language/lib/include/pl/patterns/pattern_array_dynamic.hpp.orig	2022-07-07 16:41:14 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_array_dynamic.hpp
@@ -83,7 +83,7 @@ namespace pl {
             }
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             std::string result;
 
             result += "[ ";
