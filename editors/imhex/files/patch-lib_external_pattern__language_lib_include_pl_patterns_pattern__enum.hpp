--- lib/external/pattern_language/lib/include/pl/patterns/pattern_enum.hpp.orig	2022-07-07 16:53:35 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_enum.hpp
@@ -60,7 +60,7 @@ namespace pl {
             return this->formatDisplayValue(fmt::format("{} (0x{:0{}X})", this->toString().c_str(), this->getValue(), this->getSize() * 2), this);
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             u64 value = this->getValue();
 
             std::string valueString = this->getTypeName() + "::";
