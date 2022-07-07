--- lib/external/pattern_language/lib/include/pl/patterns/pattern_boolean.hpp.orig	2022-07-07 16:47:26 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_boolean.hpp
@@ -37,7 +37,7 @@ namespace pl {
             v.visit(*this);
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             return fmt::format("{}", this->getValue() ? "true" : "false");
         }
     };
