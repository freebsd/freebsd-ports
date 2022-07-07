--- lib/external/pattern_language/lib/include/pl/patterns/pattern_union.hpp.orig	2022-07-07 16:56:20 UTC
+++ lib/external/pattern_language/lib/include/pl/patterns/pattern_union.hpp
@@ -80,7 +80,7 @@ namespace pl {
             }
         }
 
-        [[nodiscard]] virtual std::string toString() const {
+        [[nodiscard]] std::string toString() const override {
             std::string result = this->getFormattedName();
             result += " { ";
 
