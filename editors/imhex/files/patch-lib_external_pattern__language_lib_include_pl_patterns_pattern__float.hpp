--- lib/external/pattern_language/lib/include/pl/patterns/pattern_float.hpp.orig	2022-07-07 16:46:09 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_float.hpp
@@ -68,7 +68,7 @@ namespace pl {
             }
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             return fmt::format("{}", this->getValue());
         }
     };
