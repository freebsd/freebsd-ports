--- lib/external/pattern_language/lib/include/pl/patterns/pattern_bitfield.hpp.orig	2022-07-17 13:32:26 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_bitfield.hpp
@@ -67,7 +67,7 @@ namespace pl {
             return this->formatDisplayValue(fmt::format("{0} (0x{1:X})", this->getValue(), this->getValue()), u128(this->getValue()));
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             return fmt::format("{}", this->getValue());
         }
 
