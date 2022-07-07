--- lib/external/pattern_language/lib/include/pl/patterns/pattern_pointer.hpp.orig	2022-07-07 16:37:09 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_pointer.hpp
@@ -110,7 +110,7 @@ namespace pl {
             return this->formatDisplayValue(fmt::format("*(0x{0:X})", data), u128(data));
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             return this->m_pointedAt->toString();
         }
 
