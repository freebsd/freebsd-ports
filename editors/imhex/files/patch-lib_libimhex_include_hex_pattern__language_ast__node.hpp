--- lib/libimhex/include/hex/pattern_language/ast_node.hpp.orig	2022-02-15 12:57:57 UTC
+++ lib/libimhex/include/hex/pattern_language/ast_node.hpp
@@ -14,6 +14,8 @@
 #include <variant>
 #include <vector>
 
+#include <range/v3/range/concepts.hpp>
+
 namespace hex::pl {
 
     class PatternData;
@@ -1895,7 +1897,7 @@ namespace hex::pl {
         Path m_path;
 
         void readVariable(Evaluator *evaluator, auto &value, PatternData *variablePattern) const {
-            constexpr bool isString = std::same_as<std::remove_cvref_t<decltype(value)>, std::string>;
+            constexpr bool isString = ranges::same_as<std::remove_cvref_t<decltype(value)>, std::string>;
 
             if (variablePattern->isLocal()) {
                 auto &literal = evaluator->getStack()[variablePattern->getOffset()];
