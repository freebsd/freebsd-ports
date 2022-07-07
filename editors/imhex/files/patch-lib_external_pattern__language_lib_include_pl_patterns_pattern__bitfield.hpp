--- lib/external/pattern_language/lib/include/pl/patterns/pattern_bitfield.hpp.orig	2022-07-07 17:24:07 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_bitfield.hpp
@@ -67,7 +67,7 @@ namespace pl {
             return this->formatDisplayValue(fmt::format("{0} (0x{1:X})", this->getValue(), this->getValue()), u128(this->getValue()));
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             return fmt::format("{}", this->getValue());
         }
 
@@ -178,7 +178,7 @@ namespace pl {
             v.visit(*this);
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             std::string result = this->getFormattedName();
 
             result += " { ";
