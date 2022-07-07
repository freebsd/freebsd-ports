--- lib/external/pattern_language/lib/include/pl/patterns/pattern_struct.hpp.orig	2022-07-07 16:54:47 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_struct.hpp
@@ -70,7 +70,7 @@ namespace pl {
             return this->m_members;
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             std::string result = this->getFormattedName();
             result += " { ";
 
