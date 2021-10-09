--- plugins/libimhex/include/hex/pattern_language/ast_node.hpp.orig	2021-10-09 12:03:58 UTC
+++ plugins/libimhex/include/hex/pattern_language/ast_node.hpp
@@ -9,7 +9,7 @@
 #include <map>
 #include <variant>
 #include <vector>
-#include <ranges>
+#include <range/v3/view.hpp>
 
 #include <hex/pattern_language/ast_node_base.hpp>
 
@@ -1437,7 +1437,7 @@ namespace hex::pl {
                         continue;
                     } else {
                         bool found = false;
-                        for (const auto &variable : (searchScope | std::views::reverse)) {
+                        for (const auto &variable : (searchScope | ranges::views::reverse)) {
                             if (variable->getVariableName() == name) {
                                 auto newPattern = variable->clone();
                                 delete currPattern;
