--- lib/external/pattern_language/lib/include/pl/patterns/pattern_character.hpp.orig	2022-07-07 16:48:34 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_character.hpp
@@ -34,7 +34,7 @@ namespace pl {
             v.visit(*this);
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             return fmt::format("{}", this->getValue());
         }
     };
