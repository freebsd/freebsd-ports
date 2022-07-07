--- lib/external/pattern_language/lib/include/pl/patterns/pattern_signed.hpp.orig	2022-07-07 16:44:56 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_signed.hpp
@@ -49,7 +49,7 @@ namespace pl {
             return this->formatDisplayValue(fmt::format("{:d} (0x{:0{}X})", data, data, 1 * 2), data);
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             return fmt::format("{}", this->getValue());
         }
     };
